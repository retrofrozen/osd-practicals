#include<stdio.h>
int i,j,nof,nor,flag=0,ref[50],frm[50],pf=0,victim=-1;
int recent[10],lrucal[50],count=0;
int lruvictim() {
    int i,j,temp1,temp2;
    for(i=0;i<nof;i++) {
        temp1=frm[i];
        lrucal[i]=recent[temp1];
    }
    temp2 = lrucal[0];
    for(j = 1;j < nof;j++) {
        if(temp2 > lrucal[j])
            temp2 = lrucal[j];
    }
    for(i=0;i<nof;i++)
        if(ref[temp2]==frm[i])
            return i;
    return 0;
}

void main() {
    printf("LRU PAGE REPLACEMENT ALGORITHM");
    printf("\n-------------------------------");
    printf("\nEnter no.of Frames : ");
    scanf("%d",&nof);
    printf("\nEnter no. of Pages : ");
    scanf("%d",&nor);
    printf("\nEnter the Reference String : ");
    for(i=0;i<nor;i++)
        scanf("%d",&ref[i]);

    printf("\nThe given Reference String :");
    for(i=0;i<nor;i++)
        printf("%4d",ref[i]);
    for(i=1;i<=nof;i++) {
        frm[i]=-1;
        lrucal[i]=0;
    }
    for(i=0;i<10;i++)
        recent[i]=0;
    printf("\n");
    for(i=0;i<nor;i++) {
        flag=0;
        printf("\n\tReference no. %d ->\t",ref[i]);
        for(j=0;j<nof;j++) {
            if(frm[j]==ref[i]) {
                flag=1;
                break;
            }
        }
        if(flag==0) {
            count++;
            if(count<=nof)
                victim++;
            else
                victim=lruvictim();
            pf++;
            frm[victim]=ref[i];
            for(j=0;j<nof;j++)
                printf("%4d",frm[j]);
        }
        recent[ref[i]]=i;
    }
    printf("\nNo.of page faults : %d\n",pf);
}
