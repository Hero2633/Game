#define  _CRT_SECURE_NO_WARNINGS 0
#include<stdio.h>
//int main()
//{
//	int a = 1;
//
//	void* x = (void*)&a;
//	//*x = 19;
//	return 0;
//}
//int main()
//{
//	///*char a = 'abc';
//	//char* p = &a + 2;*/
//	///*printf("%c\n",*p);*/
//	//int a = "abcd";
//	//char* p = (char*)a;
//	//*p = 100;
//	//printf("%c\n",*p);
//
//
//	return 0;
//}
//int main()
//{int i = 0;
//	for (i=0; i <= 255; i++)
//		printf("%c ",i);
//
//	return 0;
//}
//int main()
//{
//	unsigned char i = 0;
//	for (i = 0; i < 255; i++)
//		printf("%c\n",i);
//
//	return 0;
//}
#include<windows.h>
//int main()
//{
//	char* s = "****";
//	int i = 0;
//	while (1)
//	{
//		i %= 4;
//		printf("[%c]\r",s[i]);
//		i++;
//		Sleep(30);
//	}
//
//
//	return 0;
//}///旋转光标；
// 
// 
// 
//int main()
//{
//	int i = 10;
//	//int a[] = { 10,9,8,7,6,5,4,3,2,1,0 };
//	while (i>-1)
//	{
//		//i %= 11;
//		printf("[%2d]\r",i);
//		//fflush(stdin);
//		Sleep(1000);
//		i--;
//	}
//
//	return 0;
//}/////////////倒计时计时器；
//#include<stdio.h>
//int main()
//{
//
//    int n = 0;
//    while (EOF != scanf("%d", &n))
//    {
//
//        while (n--)
//        {
//            printf("*");
//        }
//        putchar('\n');
//
//    }
//
//    return 0;
//}
//#include<stdio.h>
//int main()
//{
//
//    int n = 0;
//    while (EOF != scanf("%d", &n))
//    {
//        int r = 0;
//        int c = 0;
//        for (r=0; r < n; r++)
//        {
//
//            for (c=0; c < n; c++)
//            {
//                putchar('*');
//                putchar(' ');
//
//            }
//            putchar('\n');
//
//        }
//
//
//
//    }
//
//
//
//    return 0;
//}
//#include<stdio.h>
//int main()
//{
//    int n = 0;
//    while (EOF != scanf("%d", &n))
//    {
//        int r = 0;
//        int c = 0;
//        for (r = 0; r < n; r++)
//        {
//            for (c = 0; c <= r; c++)
//                printf("%c ", '*');
//            printf("%c", '\n');
//        }
//        
//    }
//    return 0;
//}#include<stdio.h>
//int main()
//{
//    int n = 0;
//    while (EOF != scanf("%d", &n))
//    {
//        int r = 0;
//        int c = 0;
//        for (r = n; r >= 1; r--)
//        {
//            for (c = 1; c <= r; c++)
//            {
//                printf("%c ", '*');
//            }
//            printf("%c", '\n');
//
//        }
//
//    }
 /*   return 0;
}*/
//#include<stdio.h>
//int main()
//{
//
//    int n = 0;
//    while (EOF != scanf("%d", &n))
//    {
//        int i = 0;
//        int j = 0;
//        int r = 1;
//        for (r = 1; r <= n; r++)
//        {
//            for (i = 1; i <= n - r; i++)
//                printf("  ");
//            for (j = 1; j <= r; j++)
//            {
//                printf("%c ", '*');
//            }
//            printf("\n");
//        }
//
//    }
//
//    return 0;
//}
//#include<stdio.h>
//int main()
//{
//    int n = 0;
//    while (EOF != scanf("%d", &n))
//    {
//        n++;
//        int i = 0;
//        int j = 0;
//        int c = 0;
//        for (c = 1; c <= n; c++)
//        {
//            for (i = 1; i <= n - c; i++)
//                printf(" ");
//            for (j = 1; j <= c; j++)
//                printf("* ");
//            printf("\n");
//        }
//    }
//    return 0;
//}
//#include<stdio.h>
//int main()
//{
//    int n = 0;
//    while (EOF != scanf("%d", &n))
//    {
//        int i = 0;
//        int j = 0;
//        int c = 0;
//        for (c = n; c >= 1; c--)
//        {
//            for (i = 1; i <= n - c+1; i++)
//                printf(" ");
//            for (j = 1; j <= c; j++)
//                printf("* ");
//            printf("\n");
//        }
//    }
//    return 0;
//}
//#include<stdio.h>
//int main()
//{
//    int n=0;
//    while(EOF!=scanf("%d",&n))
//    {
//        int i = 0;
//      int j = 0;
//        int c = 0;
      /*  n = n + 1;
        for (c = 1; c <= n; c++)
        {
            for (i = 1; i <= n - c; i++)
                printf(" ");
         for (j = 1; j <= c; j++)
        printf("* ");
          printf("\n");
    }*/
   /*        n=n-1;
  i = 0;
  j = 0;
  c = 0;
 for (c = n; c >= 1; c--)
 {    printf(" ");
     for (i = 1; i <= n - c; i++)
         printf(" ");
     for (j = 1; j <= c; j++)
         printf("* ");
     printf("\n");
 }
         
    }
   
    return 0;
}*/
//#include<stdio.h>
//int main()
//{
//    int n = 0;
//    while (EOF != scanf("%d", &n))
//    {
//        int key = 0;
//        int i = 0;
//        int j = 0;
//      key=  ++n;
//      for (i = 0; i < key; i++)
//      {
//          for(j=key-i;j>0;j--)
//          printf("* ");  
//          putchar('\n');
//      }
//      n = --n;
//      for (i = 1; i <=n; i++)
//      {
//          for (j = 0; j <= i; j++)
//              printf("* ");
//          putchar('\n');
//      }
//
//    }
//
//    return 0;
//}
//#include<stdio.h>
//int main()
//{
//    int n = 0;
//    while (EOF != scanf("%d", &n))
//    {
//        int i = 0;
//        int j = 0;
//        int k = 2 * n;
//        int a = 0;
//        for (a = 1; a <= n + 1; a++)
//        {
//            for (i = 0; i < k; i += 1)
//                printf(" ");
//            for (j = 1; j <= a; j++)
//                printf("*");
//            k -= 2;
//            putchar('\n');
//        }
//        for (i=0;i<n;i++)
//        {
//            for (j = 0; j < (i+1) * 2; j++)
//                printf(" ");
//            for (a = 1; a <= n-i; a++)
//                printf("*");
//
//            putchar('\n');
//
//        }
//
//    }
//
//    return 0;
//}
//#include<stdio.h>
//int main()
//{
//    int n = 0;
//    while (EOF!=scanf("%d",&n))
//    {
//        int i = 0;
//        int j = 0;
//        for (int k = 0; k < n; k++)
//        {
//            for (i = n - k; i < n; i++)
//            {
//                printf(" ");
//            }
//            for (j = 0; j < 1; j++)
//                printf("*");
//            putchar('\n');
//        }
//    }
//
//    return 0;
//}
//#include<stdio.h>
//int main()
//{ 
//    int n = 0;
//    while (EOF!=scanf("%d",&n))
//    {
//        int k = 0;
//        int i = 0;
//        for (i=0;i<n;i++)
//        {
//            printf("* ");
//        }putchar('\n');
//        int j = 0;
//        int a = 0;
//        for (a = 0; a < n - 2; a++)
//        {
//            printf("* ");
//            for (j = 0; j < n - 2; j++)
//                printf("  ");
//            printf("*\n");
//        }
//        for (i = 0; i < n; i++)
//        {
//            printf("* ");
//        }putchar('\n');
//    }
//
//    return 0;
//}
//#include<stdio.h>
//int main()
//{
//    int n = 0;
//    while (EOF != scanf("%d", &n))
//    {
//        int i = 0;
//        int j = 0;
//        printf("*\n");
//        int a = 1;
//        for (a=1;a<=n-2;a++)
//        {
//            printf("*");
//            for (j = 1; j <= 2 * a - 1; j++)
//                printf(" ");
//            printf("*\n");
//        }
//        for (i = 0; i < n; i++)
//        {
//            printf("* ");
//        }
//        putchar('\n');
//    }
//
//    return 0;
//}
//#include<stdio.h>
//int main()
//{
//    int n = 0;
//    while (EOF != scanf("%d", &n))
//    {
//        int i = 0;
//        int j = 0;
//        for (i=1;i<=n;i+=1)
//        {
//            for (j = 1; j <= i; j++)
//            {
//
//                printf("%d ",j);
//            }
//            putchar('\n');
//        }
//    }
//
//    return 0;
//}
#include<stdio.h>
//int main()
//{
//	int a = 1;
//
//	void* x = (void*)&a;
//	//*x = 19;
//	return 0;
//}
//int main()
//{
//	///*char a = 'abc';
//	//char* p = &a + 2;*/
//	///*printf("%c\n",*p);*/
//	//int a = "abcd";
//	//char* p = (char*)a;
//	//*p = 100;
//	//printf("%c\n",*p);
//
//
//	return 0;
//}
//int main()
//{int i = 0;
//	for (i=0; i <= 255; i++)
//		printf("%c ",i);
//
//	return 0;
//}
//int main()
//{
//	unsigned char i = 0;
//	for (i = 0; i < 255; i++)
//		printf("%c\n",i);
//
//	return 0;
//}
#include<windows.h>
//int main()
//{
//	char* s = "****";
//	int i = 0;
//	while (1)
//	{
//		i %= 4;
//		printf("[%c]\r",s[i]);
//		i++;
//		Sleep(30);
//	}
//
//
//	return 0;
//}///旋转光标；
// 
// 
// 
//int main()
//{
//	int i = 10;
//	//int a[] = { 10,9,8,7,6,5,4,3,2,1,0 };
//	while (i>-1)
//	{
//		//i %= 11;
//		printf("[%2d]\r",i);
//		//fflush(stdin);
//		Sleep(1000);
//		i--;
//	}
//
//	return 0;
//}/////////////倒计时计时器；
//#include<stdio.h>
//int main()
//{
//
//    int n = 0;
//    while (EOF != scanf("%d", &n))
//    {
//
//        while (n--)
//        {
//            printf("*");
//        }
//        putchar('\n');
//
//    }
//
//    return 0;
//}
//#include<stdio.h>
//int main()
//{
//
//    int n = 0;
//    while (EOF != scanf("%d", &n))
//    {
//        int r = 0;
//        int c = 0;
//        for (r=0; r < n; r++)
//        {
//
//            for (c=0; c < n; c++)
//            {
//                putchar('*');
//                putchar(' ');
//
//            }
//            putchar('\n');
//
//        }
//
//
//
//    }
//
//
//
//    return 0;
//}
//#include<stdio.h>
//int main()
//{
//    int n = 0;
//    while (EOF != scanf("%d", &n))
//    {
//        int r = 0;
//        int c = 0;
//        for (r = 0; r < n; r++)
//        {
//            for (c = 0; c <= r; c++)
//                printf("%c ", '*');
//            printf("%c", '\n');
//        }
//        
//    }
//    return 0;
//}#include<stdio.h>
//int main()
//{
//    int n = 0;
//    while (EOF != scanf("%d", &n))
//    {
//        int r = 0;
//        int c = 0;
//        for (r = n; r >= 1; r--)
//        {
//            for (c = 1; c <= r; c++)
//            {
//                printf("%c ", '*');
//            }
//            printf("%c", '\n');
//
//        }
//
//    }
 /*   return 0;
}*/
//#include<stdio.h>
//int main()
//{
//
//    int n = 0;
//    while (EOF != scanf("%d", &n))
//    {
//        int i = 0;
//        int j = 0;
//        int r = 1;
//        for (r = 1; r <= n; r++)
//        {
//            for (i = 1; i <= n - r; i++)
//                printf("  ");
//            for (j = 1; j <= r; j++)
//            {
//                printf("%c ", '*');
//            }
//            printf("\n");
//        }
//
//    }
//
//    return 0;
//}
//#include<stdio.h>
//int main()
//{
//    int n = 0;
//    while (EOF != scanf("%d", &n))
//    {
//        n++;
//        int i = 0;
//        int j = 0;
//        int c = 0;
//        for (c = 1; c <= n; c++)
//        {
//            for (i = 1; i <= n - c; i++)
//                printf(" ");
//            for (j = 1; j <= c; j++)
//                printf("* ");
//            printf("\n");
//        }
//    }
//    return 0;
//}
//#include<stdio.h>
//int main()
//{
//    int n = 0;
//    while (EOF != scanf("%d", &n))
//    {
//        int i = 0;
//        int j = 0;
//        int c = 0;
//        for (c = n; c >= 1; c--)
//        {
//            for (i = 1; i <= n - c+1; i++)
//                printf(" ");
//            for (j = 1; j <= c; j++)
//                printf("* ");
//            printf("\n");
//        }
//    }
//    return 0;
//}
//#include<stdio.h>
//int main()
//{
//    int n=0;
//    while(EOF!=scanf("%d",&n))
//    {
//        int i = 0;
//      int j = 0;
//        int c = 0;
      /*  n = n + 1;
        for (c = 1; c <= n; c++)
        {
            for (i = 1; i <= n - c; i++)
                printf(" ");
         for (j = 1; j <= c; j++)
        printf("* ");
          printf("\n");
    }*/
    /*        n=n-1;
   i = 0;
   j = 0;
   c = 0;
  for (c = n; c >= 1; c--)
  {    printf(" ");
      for (i = 1; i <= n - c; i++)
          printf(" ");
      for (j = 1; j <= c; j++)
          printf("* ");
      printf("\n");
  }

     }

     return 0;
 }*/
 //#include<stdio.h>
 //int main()
 //{
 //    int n = 0;
 //    while (EOF != scanf("%d", &n))
 //    {
 //        int key = 0;
 //        int i = 0;
 //        int j = 0;
 //      key=  ++n;
 //      for (i = 0; i < key; i++)
 //      {
 //          for(j=key-i;j>0;j--)
 //          printf("* ");  
 //          putchar('\n');
 //      }
 //      n = --n;
 //      for (i = 1; i <=n; i++)
 //      {
 //          for (j = 0; j <= i; j++)
 //              printf("* ");
 //          putchar('\n');
 //      }
 //
 //    }
 //
 //    return 0;
 //}
 //#include<stdio.h>
 //int main()
 //{
 //    int n = 0;
 //    while (EOF != scanf("%d", &n))
 //    {
 //        int i = 0;
 //        int j = 0;
 //        int k = 2 * n;
 //        int a = 0;
 //        for (a = 1; a <= n + 1; a++)
 //        {
 //            for (i = 0; i < k; i += 1)
 //                printf(" ");
 //            for (j = 1; j <= a; j++)
 //                printf("*");
 //            k -= 2;
 //            putchar('\n');
 //        }
 //        for (i=0;i<n;i++)
 //        {
 //            for (j = 0; j < (i+1) * 2; j++)
 //                printf(" ");
 //            for (a = 1; a <= n-i; a++)
 //                printf("*");
 //
 //            putchar('\n');
 //
 //        }
 //
 //    }
 //
 //    return 0;
 //}
 //#include<stdio.h>
 //int main()
 //{
 //    int n = 0;
 //    while (EOF!=scanf("%d",&n))
 //    {
 //        int i = 0;
 //        int j = 0;
 //        for (int k = 0; k < n; k++)
 //        {
 //            for (i = n - k; i < n; i++)
 //            {
 //                printf(" ");
 //            }
 //            for (j = 0; j < 1; j++)
 //                printf("*");
 //            putchar('\n');
 //        }
 //    }
 //
 //    return 0;
 //}
 //#include<stdio.h>
 //int main()
 //{ 
 //    int n = 0;
 //    while (EOF!=scanf("%d",&n))
 //    {
 //        int k = 0;
 //        int i = 0;
 //        for (i=0;i<n;i++)
 //        {
 //            printf("* ");
 //        }putchar('\n');
 //        int j = 0;
 //        int a = 0;
 //        for (a = 0; a < n - 2; a++)
 //        {
 //            printf("* ");
 //            for (j = 0; j < n - 2; j++)
 //                printf("  ");
 //            printf("*\n");
 //        }
 //        for (i = 0; i < n; i++)
 //        {
 //            printf("* ");
 //        }putchar('\n');
 //    }
 //
 //    return 0;
 //}
 //#include<stdio.h>
 //int main()
 //{
 //    int n = 0;
 //    while (EOF != scanf("%d", &n))
 //    {
 //        int i = 0;
 //        int j = 0;
 //        printf("*\n");
 //        int a = 1;
 //        for (a=1;a<=n-2;a++)
 //        {
 //            printf("*");
 //            for (j = 1; j <= 2 * a - 1; j++)
 //                printf(" ");
 //            printf("*\n");
 //        }
 //        for (i = 0; i < n; i++)
 //        {
 //            printf("* ");
 //        }
 //        putchar('\n');
 //    }
 //
 //    return 0;
 //}
 //#include<stdio.h>
 //int main()
 //{
 //    int n = 0;
 //    while (EOF != scanf("%d", &n))
 //    {
 //        int i = 0;
 //        int j = 0;
 //        for (i=1;i<=n;i+=1)
 //        {
 //            for (j = 1; j <= i; j++)
 //            {
 //
 //                printf("%d ",j);
 //            }
 //            putchar('\n');
 //        }
 //    }
 //
 //    return 0;
 //}