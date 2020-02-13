#include<stdio.h>
int i, j, nof, nor, flag=0, ref[50], frm[50], pf=0, victim=-1;
void main()
{
    printf("FIFO PAGE REPLACEMENT ALGORITHM");
    printf("\n--------------------------------");
    printf("\nEnter no.of frames : ");
    scanf("%d",&nof);
    printf("\nEnter number of Pages : ");
    scanf("%d",&nor);
    printf("\nEnter the Reference String : ");

    // Reference String Input
    for(i=0;i<nor;i++)
        scanf("%d",&ref[i]);

    // Print the Reference String
    printf("\nThe Reference String is : ");
    for(i=0;i<nor;i++)
        printf("%4d",ref[i]);

    printf("\n");

    for(i=1;i<=nof;i++)
        frm[i]=-1;

    for(i=0;i<nor;i++) {
        flag=0;
        printf("\n\t Reference no %d->\t",ref[i]);
        for(j=0;j<nof;j++) {
            if(frm[j]==ref[i]) {
                flag=1;
                break;
            }
        }

        if(flag==0) {
            pf++;
            victim++;
            victim=victim%nof;
            frm[victim]=ref[i];
            for(j=0;j<nof;j++)
                printf("%4d",frm[j]);
        }
    }
    printf("\nNo. of Page Faults : %d\n",pf);
}
