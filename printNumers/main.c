//
//  main.c
//  矩阵输出
//
//  Created by Guan on 15/7/18.
//  Copyright (c) 2015年 Guan. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    //输入一个数
    int n = 0 ;
    printf("--------------------------------------------------------------\n");
    printf("请输入一个数");
    scanf("%d",&n);
    printf("--------------------------------------------------------------\n输入了%d\n",n);
    printf("--------------------------------------------------------------\n对应的数字%d矩阵为：\n\n",n);
    
//-----------------创建数组及数组初始化-----------------------------------------
    int arr[n][n];
    
    for (int i =  0 ; i < n ; i ++) {
        for (int j = 0 ; j < n ; j ++) {
            arr[i][j] = 0 ;
        }
    }
    
    
//-----------------初始化方向计数标识、第一圈边长与数组下标-------------------------
    int flag_top = 0 ;
    
    int flag_down = 0 ;
    
    int flag_left = 0 ;
    
    int flag_right = 0 ;
    
    int count = n ;  //边长
    
    int i = 0 ;
    int j = 0 ;

//----------------从1遍历到输入数字的的平方，通过算法赋值给数组----------------------
    for (int k = 1 ; k < n * n + 1; k ++ ) {
        
//------------------赋值------------------------------------------------------
        arr[i][j] = k ;
        //        printf("r--%d , d--%d , l--%d , t--%d , i-- %d , j -- %d , arr--%d\n",flag_right,flag_down,flag_left,flag_top,i,j,k);
        
//---------------------光标右移，数组下标右移------------------------------------
        if (flag_right < count -1) {
            flag_right ++ ;
            j ++;
        }else {
            
//-----------------光标右移到顶，开始下移，数组下标开始下移-------------------------
            if (flag_down < count - 1 ) {
                flag_down ++ ;
                i++;
            }else {
                
//-----------------光标下移到顶，开始左移，数组下标开始左移-------------------------
                if (flag_left < count - 1) {
                    flag_left ++ ;
                    j -- ;
                }else {
                    
//-----------------光标左移到顶，开始上移，数组下标开始上移-------------------------
                    if (flag_top < count - 2 ) {
                        flag_top ++ ;
                        i -- ;
                        
//----------光标做完一圈，方向计数清零，下一圈边长减2，i,j初始化---------------------
                    }else {
                        flag_top = 0 ;
                        
                        flag_down = 0 ;
                        
                        flag_left = 0 ;
                        
                        flag_right = 0 ;
                        
                        count = count - 2   ;
                        
                        j = i ;
                    }
                    
                }
                
                
            }
            
            
        }
        
    }
    
    
//-----------------遍历数组，打印数字矩阵----------------------------------------
    for (int i = 0; i < n ; i ++) {
        for (int j = 0 ; j < n ; j ++ ) {
            printf("%4d ",arr[i][j]);
        }
        printf("\n \n");
    }
    
  printf("--------------------------------------------------------------\n");
    return 0;
}
