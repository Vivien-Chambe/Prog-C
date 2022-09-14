#include <stdio.h>
void print_state(int a[],int an)
    {
        for (int cpt = 0; cpt < an ; cpt ++)
        {
            if (a[cpt]==0)
            	{
            	printf (" ");
            	}
            else
                {
                printf("*");
                }
        }
        printf("\n");
     	return;
    }

void rule_30(int a[], int an, int nsteps){
    int b[an];
    int gauche,milieu,droit;
	for (int i=0; i<nsteps; i++){
        print_state(a,an);
		for (int j=0; j<an;j++){
            if (j == 0){
                gauche = 0;
            } 
            else{gauche = a[j-1];}
            if (j == an-1){
                droit  = 0;
            } 
            else{droit = a[j+1];}
            milieu = a[j];
        
            if ((gauche && milieu && droit ) || (gauche && milieu && !droit ) || (gauche && !milieu && droit ) || (!gauche && !milieu && !droit )){
                b[j] = 0;
            }
            else{ 
                b[j]=1;
            }
        }
        a = b;

	}
}

int main() 
    {
        int a[7]={0,0,0,1,0,0,0};
        rule_30(a,7,10);
        return 0;
    }
