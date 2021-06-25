#include <stdio.h>
#include <math.h>

typedef struct judge jd;  
struct judge{
    float score;
    int judgeNo;
}Judge[10];

void sort(jd a[]){
    int isSorted;
    for(int i=0; i<9; i++){
        isSorted = 1;
        for(int j=0; j<9-i; j++){
            if(a[j].score < a[j+1].score){
                isSorted = 0;
                jd temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
        if(isSorted) return;
    }
}

int findfair(jd a[],float sum){
    int i=4,k=5;
    float tmp=fabs(a[5].score - sum);
    while(fabs(a[i].score -sum)<tmp){
        k=i;
        tmp = fabs(a[i--].score -sum);
    }
    i=6;
    while(fabs(a[i].score -sum)<tmp){
        k=i;
        tmp = fabs(a[i++].score -sum);
    }
    return a[k].judgeNo;
}
int main(){
    int n,i;
    float sum=0;
    printf("Input the number of singers:");
    scanf("%d",&n);
    while(n--){
        sum=0;
        for (i=0;i<10;i++){
            scanf("%f",&Judge[i].score);
            sum+=Judge[i].score;
            Judge[i].judgeNo = i;
        }
        sort(Judge);
        for (i=0;i<10;i++){
            printf("%f ",Judge[i].score);
        }
        printf("\n");
        sum = (sum - Judge[0].score - Judge[9].score)/8;
        printf("The score is:%f\n",sum);
        printf("The most unfair judge is:%d\n",fabs(Judge[0].score - sum)>fabs(Judge[9].score - sum) ? Judge[0].judgeNo : Judge[9].judgeNo);
        printf("The most fair judge is:%d\n",findfair(Judge,sum));
    }
}