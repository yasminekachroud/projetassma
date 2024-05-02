#include "collision.h"
#include <math.h> // Incluez math.h pour avoir accès à la fonction sqrt

int collisionTRI(Circle c1, Circle c2) {
    // Calcul de la distance entre les centres des cercles
    float distance = sqrt((c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y));

    // Test de collision en comparant la distance avec la somme des rayons
    if (distance <= c1.radius + c2.radius) {
        return 1;  
    } else {
        return 0;  
    }
}

