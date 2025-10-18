#!/bin/bash

# Couleurs pour l'affichage
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Compteurs
TOTAL=0
PASSED=0
FAILED=0

# Fonction pour tester une map
test_map() {
    local map=$1
    local should_pass=$2
    local description=$3
    
    TOTAL=$((TOTAL + 1))
    
    echo -e "\n${BLUE}Test $TOTAL: ${description}${NC}"
    echo -e "Map: ${map}"
    
    # Tester la map
    has_leak=0
    VALGRIND_OPTS="--leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=42"
    
    if [ "$should_pass" = "valid" ]; then
        # Maps valides : sans valgrind (ouvrent une fenêtre MLX, impossibles à tester avec valgrind)
        timeout 2 ./cub3D "$map" > /dev/null 2>&1
        exit_code=$?
    else
        # Maps invalides : avec valgrind complet (sortent immédiatement avec erreur)
        timeout 2 valgrind $VALGRIND_OPTS ./cub3D "$map" > /dev/null 2>&1
        exit_code=$?
        # Vérifier si leak détecté
        if [ $exit_code -eq 42 ]; then
            has_leak=1
        fi
    fi
    
    # Vérifier le résultat
    if [ "$should_pass" = "valid" ]; then
        if [ $exit_code -eq 0 ] || [ $exit_code -eq 124 ]; then
            if [ $has_leak -eq 1 ]; then
                echo -e "${YELLOW}✓ PASS (avec memory leak)${NC} - Map valide acceptée"
            else
                echo -e "${GREEN}✓ PASS${NC} - Map valide acceptée"
            fi
            PASSED=$((PASSED + 1))
        else
            echo -e "${RED}✗ FAIL${NC} - Map valide rejetée (exit code: $exit_code)"
            FAILED=$((FAILED + 1))
        fi
    else
        if [ $exit_code -ne 0 ] && [ $exit_code -ne 124 ] && [ $exit_code -ne 42 ]; then
            if [ $has_leak -eq 1 ]; then
                echo -e "${YELLOW}✓ PASS (avec memory leak)${NC} - Map invalide rejetée"
            else
                echo -e "${GREEN}✓ PASS${NC} - Map invalide rejetée"
            fi
            PASSED=$((PASSED + 1))
        else
            echo -e "${RED}✗ FAIL${NC} - Map invalide acceptée"
            FAILED=$((FAILED + 1))
        fi
    fi
}

echo -e "${YELLOW}========================================${NC}"
echo -e "${YELLOW}    CUB3D MAP VALIDATION TEST SUITE    ${NC}"
echo -e "${YELLOW}========================================${NC}"

echo -e "${YELLOW}Valgrind activé sur maps invalides (détection memory leaks)${NC}"
echo -e "${YELLOW}Note: Maps valides non testées avec valgrind (ouvrent fenêtre MLX)${NC}"

# Vérifier que l'exécutable existe
if [ ! -f "./cub3D" ]; then
    echo -e "${RED}Erreur: ./cub3D n'existe pas${NC}"
    echo "Compilation en cours..."
    make
    if [ ! -f "./cub3D" ]; then
        echo -e "${RED}Erreur: Compilation échouée${NC}"
        exit 1
    fi
fi

# ============================================
# TESTS DE MAPS VALIDES
# ============================================
echo -e "\n${YELLOW}=== TESTS DE MAPS VALIDES ===${NC}"

test_map "test_maps/valid/spawn_north.cub" "valid" "Spawn orientation NORTH"
test_map "test_maps/valid/spawn_south.cub" "valid" "Spawn orientation SOUTH"
test_map "test_maps/valid/spawn_east.cub" "valid" "Spawn orientation EAST"
test_map "test_maps/valid/spawn_west.cub" "valid" "Spawn orientation WEST"
test_map "test_maps/valid/big_map.cub" "valid" "Grande map valide"
test_map "test_maps/valid/tiny_map.cub" "valid" "Petite map valide"

# ============================================
# TESTS DE CONFIGURATION INVALIDE
# ============================================
echo -e "\n${YELLOW}=== TESTS DE CONFIGURATION INVALIDE ===${NC}"

test_map "test_maps/invalid/missing_ea_texture.cub" "invalid" "Texture EA manquante"
test_map "test_maps/invalid/missing_floor_color.cub" "invalid" "Couleur sol manquante"
test_map "test_maps/invalid/missing_ceiling_color.cub" "invalid" "Couleur plafond manquante"
test_map "test_maps/invalid/double_no_texture.cub" "invalid" "Double déclaration NO"
test_map "test_maps/invalid/double_floor_color.cub" "invalid" "Double déclaration F"
test_map "test_maps/invalid/invalid_texture_path.cub" "invalid" "Chemin de texture invalide"
test_map "test_maps/invalid/unknown_identifier.cub" "invalid" "Identifiant inconnu"

# ============================================
# TESTS DE COULEURS INVALIDES
# ============================================
echo -e "\n${YELLOW}=== TESTS DE COULEURS INVALIDES ===${NC}"

test_map "test_maps/invalid/color_out_of_range.cub" "invalid" "Couleur hors limite (>255)"
test_map "test_maps/invalid/negative_color.cub" "invalid" "Couleur négative"
test_map "test_maps/invalid/incomplete_color.cub" "invalid" "Couleur incomplète (RGB incomplet)"

# ============================================
# TESTS DE MAP INVALIDE
# ============================================
echo -e "\n${YELLOW}=== TESTS DE MAP INVALIDE ===${NC}"

test_map "test_maps/invalid/no_player.cub" "invalid" "Pas de joueur"
test_map "test_maps/invalid/multiple_players.cub" "invalid" "Plusieurs joueurs"
test_map "test_maps/invalid/map_not_closed_left.cub" "invalid" "Map ouverte à gauche"
test_map "test_maps/invalid/map_not_closed_right.cub" "invalid" "Map ouverte à droite"
test_map "test_maps/invalid/map_not_closed_top.cub" "invalid" "Map ouverte en haut"
test_map "test_maps/invalid/map_not_closed_bottom.cub" "invalid" "Map ouverte en bas"
test_map "test_maps/invalid/invalid_character.cub" "invalid" "Caractère invalide dans map"
test_map "test_maps/invalid/empty_line_in_middle_of_map.cub" "invalid" "Ligne vide au milieu de la map"
test_map "test_maps/invalid/no_map.cub" "invalid" "Pas de map"
test_map "test_maps/invalid/map_weird_1.cub" "invalid" "Map bizarre 1 (lignes inégales + espace)"
test_map "test_maps/invalid/map_weird_2.cub" "invalid" "Map bizarre 2 (commence par espace)"
test_map "test_maps/invalid/Big_map.cub" "invalid" "Grande map complexe avec espaces"

# Test sans arguments
echo -e "\n${BLUE}Test $((TOTAL + 1)): Programme sans arguments${NC}"
TOTAL=$((TOTAL + 1))
./cub3D > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo -e "${GREEN}✓ PASS${NC} - Erreur détectée sans arguments"
    PASSED=$((PASSED + 1))
else
    echo -e "${RED}✗ FAIL${NC} - Aucune erreur sans arguments"
    FAILED=$((FAILED + 1))
fi

# Test avec fichier inexistant
echo -e "\n${BLUE}Test $((TOTAL + 1)): Fichier inexistant${NC}"
TOTAL=$((TOTAL + 1))
./cub3D nonexistent.cub > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo -e "${GREEN}✓ PASS${NC} - Erreur détectée pour fichier inexistant"
    PASSED=$((PASSED + 1))
else
    echo -e "${RED}✗ FAIL${NC} - Aucune erreur pour fichier inexistant"
    FAILED=$((FAILED + 1))
fi

# Test avec mauvaise extension
echo -e "\n${BLUE}Test $((TOTAL + 1)): Mauvaise extension (.txt)${NC}"
TOTAL=$((TOTAL + 1))
touch /tmp/test.txt
./cub3D /tmp/test.txt > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo -e "${GREEN}✓ PASS${NC} - Erreur détectée pour mauvaise extension"
    PASSED=$((PASSED + 1))
else
    echo -e "${RED}✗ FAIL${NC} - Aucune erreur pour mauvaise extension"
    FAILED=$((FAILED + 1))
fi
rm -f /tmp/test.txt

# Test avec mauvaise extension (.cu)
echo -e "\n${BLUE}Test $((TOTAL + 1)): Extension presque valide (.cu)${NC}"
TOTAL=$((TOTAL + 1))
cp test_maps/valid/spawn_north.cub /tmp/test.cu
./cub3D /tmp/test.cu > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo -e "${GREEN}✓ PASS${NC} - Erreur détectée pour extension .cu"
    PASSED=$((PASSED + 1))
else
    echo -e "${RED}✗ FAIL${NC} - Aucune erreur pour extension .cu"
    FAILED=$((FAILED + 1))
fi
rm -f /tmp/test.cu

# Test avec trop d'arguments
echo -e "\n${BLUE}Test $((TOTAL + 1)): Trop d'arguments${NC}"
TOTAL=$((TOTAL + 1))
./cub3D test_maps/valid/spawn_north.cub extra_arg > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo -e "${GREEN}✓ PASS${NC} - Erreur détectée pour trop d'arguments"
    PASSED=$((PASSED + 1))
else
    echo -e "${RED}✗ FAIL${NC} - Aucune erreur pour trop d'arguments"
    FAILED=$((FAILED + 1))
fi

# ============================================
# RÉSUMÉ
# ============================================
echo -e "\n${YELLOW}========================================${NC}"
echo -e "${YELLOW}              RÉSUMÉ                    ${NC}"
echo -e "${YELLOW}========================================${NC}"
echo -e "Total de tests: ${TOTAL}"
echo -e "${GREEN}Tests réussis: ${PASSED}${NC}"
echo -e "${RED}Tests échoués: ${FAILED}${NC}"

if [ $FAILED -eq 0 ]; then
    echo -e "\n${GREEN}✓ TOUS LES TESTS SONT PASSÉS !${NC}"
    exit 0
else
    echo -e "\n${RED}✗ CERTAINS TESTS ONT ÉCHOUÉ${NC}"
    exit 1
fi
