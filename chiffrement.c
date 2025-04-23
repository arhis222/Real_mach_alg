
/*
#include <stdio.h>
#include <stdlib.h>
#include<math.h>

/* Utilisation: donnez l'entier � chiffrer m puis la cl� (exp,n)*/
/* attention m doit �tre inf�rieur � n */
/* le r�sultat est dans code */

/* Exemples de cl�s: (565, 283189) , (140313, 283189)       
/*                   (13,77), (37 77) 

void main(int argc, char * argv[])
{
    unsigned long int m,exp,n;
    unsigned long int code;

    if (argc != 4) exit(0);
    sscanf(argv[1], "%ld", &m);
    sscanf(argv[2], "%ld", &exp);
    sscanf(argv[3], "%ld", &n);
    
	code=1;
	while (exp>0)
	{
		if ((exp&1)>0) 
		{
		code= (code * m)%n;
		}	
		exp=exp>>1;
		m= (m*m)%n;
	}
	printf("Resultat chiffrement %ld\n",  code);
}
*/

// La version modifiée de l'algo (question 2) :

#include <stdio.h>
#include <stdlib.h>

void main(int argc, char * argv[])
{
    unsigned long int m, exp, n;
    unsigned long int code, temp;

    if (argc != 4) exit(0);
    sscanf(argv[1], "%ld", &m);
    sscanf(argv[2], "%ld", &exp);
    sscanf(argv[3], "%ld", &n);
    
    code = 1;
    while (exp > 0) // exp != 0 donc flag (not Z)
    {
        if ((exp & 1) > 0)  //(LSB == 1) Last Significant Bit
        {
            // code = (code * m) % n, calculé par soustractions répétées
            code = code * m;
            while (code >= n) //while C
                code = code - n;
            
        }
        exp = exp >> 1;  // màj flag Z 
        // m = (m * m) % n, calculé par soustractions répétées
        m = m * m;
        while (m >= n) //while C
            m = m - n;
        
    }
    printf("Resultat chiffrement %ld\n", code);
}
