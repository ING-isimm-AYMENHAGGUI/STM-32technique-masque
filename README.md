# stm-technique_masque
Sur les microcontrôleurs les périphériques sont configurés et contrôlés à travers des registres ayant une adresse mémoire réservée. Cela signifie que l’accès et la configuration d’un périphérique se fait au niveau du code simplement en écrivant ou en lisant à des adresses mémoires spécifiques.

Pour mettre un seul bit à 1 dans un registre, nous utilisons l’opérateur bit-à-bit OU avec un masque dont tous les bits sont à 0, sauf celui que l’on veut initialiser.

Pour mettre des bits à 0, nous utilisons l’opérateur bit-à-bit ET avec un masque ayant des bits à 0 uniquement devant les bits que nous voulons initialiser. 

Les opérateurs bit-à-bit peuvent aussi servir pour tester la valeur d’un bit dans un registre. Pour cela, il faut créer un masque en mettant à 0 tous les bits qui n’ont pas d’intérêt pour le test à faire, puis l’utiliser avec l’opérateur bit-à-bit ET.

À la fin de ce projet, vous êtes capable :

d'utiliser les opérateurs bits-à-bits en C,

d'expliquer et de mettre en pratique un masque pour manipuler les bits d'un registre. 
