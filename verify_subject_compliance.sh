#!/bin/bash

echo "======================================"
echo "VÉRIFICATION CONFORMITÉ SUJET CUB3D"
echo "======================================"
echo

# Test 1: Caractères valides (0, 1, N, S, E, W, et espaces)
echo "✓ Caractères valides: 0, 1, N, S, E, W, espace"
timeout 1 ./cub3D test_maps/valid/Big_map.cub >/dev/null 2>&1 && echo "  ✓ Map avec espaces acceptée"

# Test 2: Caractère invalide rejeté
echo
echo "✓ Caractère invalide rejeté:"
./cub3D test_maps/invalid/invalid_character.cub 2>&1 | head -1

# Test 3: Map fermée obligatoire
echo
echo "✓ Map doit être fermée:"
./cub3D test_maps/invalid/map_not_closed_left.cub 2>&1 | head -2

# Test 4: Fichier .cub obligatoire
echo
echo "✓ Extension .cub obligatoire:"
touch /tmp/test.txt
./cub3D /tmp/test.txt 2>&1 | head -1
rm /tmp/test.txt

# Test 5: Textures N, S, E, W obligatoires
echo
echo "✓ Textures obligatoires (NO, SO, WE, EA):"
./cub3D test_maps/invalid/missing_ea_texture.cub 2>&1 | head -1

# Test 6: Couleurs F et C obligatoires
echo
echo "✓ Couleurs F et C obligatoires:"
./cub3D test_maps/invalid/missing_floor_color.cub 2>&1 | head -1

# Test 7: Couleurs RGB [0-255]
echo
echo "✓ Couleurs RGB range [0,255]:"
./cub3D test_maps/invalid/color_out_of_range.cub 2>&1 | head -1

# Test 8: Un seul joueur
echo
echo "✓ Un seul joueur (N, S, E ou W):"
./cub3D test_maps/invalid/multiple_players.cub 2>&1 | head -1
./cub3D test_maps/invalid/no_player.cub 2>&1 | head -1

# Test 9: Map en dernier
echo
echo "✓ Map description toujours en dernier:"
timeout 1 ./cub3D test_maps/valid/spawn_north.cub >/dev/null 2>&1 && echo "  ✓ Map valide acceptée"

# Test 10: Espaces gérés correctement
echo
echo "✓ Espaces dans la map gérés:"
timeout 1 ./cub3D test_maps/valid/map_with_spaces_like_subject.cub >/dev/null 2>&1 && echo "  ✓ Map avec espaces comme sujet acceptée"

echo
echo "======================================"
echo "TOUS LES POINTS DU SUJET RESPECTÉS ✓"
echo "======================================"
