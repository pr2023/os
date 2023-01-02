#include<stdio.h>
struct node
{
  int pno,reftime;
}frames[20];
int n;

int page_found(int pno)
{
  int fno;
  for(fno=0;fno<n;fno++)
	if(frames[fno].pno==pno)
	   return fno;
	return -1;
}

int get_free_frame()
{  int fno;
  for (fno=0; fno<=n; fno++)
	if (frames[fno].pno==-1)
		return(fno);
   return(-1);
}

int get_lru_frame()
{
  int fno;
  int selfno=0;
  for (fno=1; fno<n; fno++)
	if(frames[fno].reftime<frames[selfno].reftime)
	selfno=fno;
  return selfno;
}
main()
{
   int p_request[]={3,5,7,2,5,1,2,3,1,3,5,3,1,6,2};
   int size=15,currtime;
   int page_falts=0,i,j,fno;
  
   printf("\nHow many frames:");  scanf("%d",&n);
   
   for (i=0; i<n; i++)
   { frames[i].pno=-1;
	 frames[i].reftime=-1;
   }

   printf("\nPageNo     Page Frames          Page Fault");
   printf("\n-------------------------------------------");
   currtime=0;
   for(i=0;i<size;i++)
   {
	 j=page_found(p_request[i]);
	 if(j==-1)  //page fault occurs
	 {
	   j=get_free_frame();
	   if (j==-1) 
		 j=get_lru_frame();
	   page_falts++;
	   frames[j].pno=p_request[i];
	   frames[j].reftime=currtime;
	   printf("\n%4d\t ",p_request[i]);
	   for (fno=0; fno<n; fno++)
		 printf("%4d",frames[fno].pno);
	   printf(" : YES");
	 }
	else
	{
	   printf("\n%4d\t ",p_request[i]);
	   frames[j].reftime=currtime;
	   for (fno=0; fno<n; fno++)
		 printf("%4d",frames[fno].pno);
	   printf(" : NO");
	}
	   currtime++;
   }
  printf("\n------------------------------------------");
  printf("\n Number of Page_Falts=%d",page_falts);

}