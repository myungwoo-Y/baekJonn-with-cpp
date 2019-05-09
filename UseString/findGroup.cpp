//
// Created by myungwoo on 19. 1. 28.
//

#include <iostream>
using namespace std;

int n,d[26],i,t,j,a;
char in[102];
int findGroup(){
    scanf("%d",&t);
    for(j=1;j<=t;j++){
        scanf("%s",in);
        d[in[0]-'a']=j;
        for(i=1;in[i];i++){
            // 문자가 바뀌는 타이밍에 이 문자를 전에 방문했는지 확인한다.
            if(in[i-1]!=in[i]&&d[in[i]-'a']==j)
                break;
            // 해당 문자 방문했다고 마크한다.
            d[in[i]-'a']=j;
        }
        if(!in[i])a++;
    }
    printf("%d",a);
}