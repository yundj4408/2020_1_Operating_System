#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#define    STACK_ALLOC    ONE_MEG/20
#define    HighPageTableSlot( Address )   (Address>>22) & 0x000003FF
#define    LowPageTableSlot( Address)     (Address>>12) & 0x000003FF
#define    Offset( Address )              Address       & 0x00000FFF
#define ONE_MEG 1048576
#define MAXTEXT 25 
#define BASE 16
#define GROUP 4

//  This is a global so the subroutine can see it.
unsigned long    FirstStackLocation;
long *MemoryPtr;				//WILL memory allocate by using malloc function
int     Global;	
int  b()   {
    Global++;
}
void     RecursiveRoutine( int );
char     *commas(unsigned long amount);
int    main( int argc, char  *argv[] ) {
    int     Stack;
    int     Address;
    int NumberofAllocations= 0; 
    int NumberofMegabytes = 3039;
    char  *Heap = malloc( 10 * sizeof(char) );
    b();
    printf( "\n\nSlicing up the logical address space\n");
    printf( "<----  10 bits  ----><----  10 bits  ----><------  12 bits  ------>\n");
    printf( "--------------------------------------------------------------------\n");
    printf( "|                    |                    |                        |\n");
    printf( "| Defines the slot   | Defines the slot   |  Offset within the     |\n");
    printf( "| in High Level Page | in Low Level Page  |  Physical Frame.       |\n");
    printf( "| Table - selects    | Table - selects    |                        |\n");
    printf( "| the low level page | the Frame in       |                        |\n");
    printf( "| table.             | Physical Memory.   |                        |\n");
    printf( "|                    |                    |                        |\n");
    printf( "--------------------------------------------------------------------\n");
    printf( "Global Data: \n");
    Address = (int)&Global;
    printf( "  Address = %8X  Low Page Table = %3X  Slot in Table = %3X  Offset = %3X\n",
            Address, HighPageTableSlot( Address ), LowPageTableSlot( Address), Offset( Address ) );
    printf( "Main - Code: \n");
    Address = (int)main;
    printf( "  Address = %8X  Low Page Table = %3X  Slot in Table = %3X  Offset = %3X\n",
            Address, HighPageTableSlot( Address ), LowPageTableSlot( Address), Offset( Address ) );
    printf( "b - Code: \n");
    Address = (int)b;
    printf( "  Address = %8X  Low Page Table = %3X  Slot in Table = %3X  Offset = %3X\n",
            Address, HighPageTableSlot( Address ), LowPageTableSlot( Address), Offset( Address ) );

	printf( "Stack: \n");
    Address = (int)&Stack;
    printf( "  Address = %8X  Low Page Table = %3X  Slot in Table = %3X  Offset = %3X\n",
            Address, HighPageTableSlot( Address ), LowPageTableSlot( Address), Offset( Address ) );
    printf( "Heap: \n");
    Address = (int)Heap;
    printf( "  Address = %8X  Low Page Table = %3X  Slot in Table = %3X  Offset = %3X\n",
            Address, HighPageTableSlot( Address ), LowPageTableSlot( Address), Offset( Address ) );
	while (NumberofAllocations < NumberofMegabytes) {
		MemoryPtr = (long* )malloc(ONE_MEG);
		if (MemoryPtr == 0) {
		printf("The program is ending because we could allocate no more memory.\n");
		printf("Total megabytes allocated = %d\n", NumberofAllocations);
		exit(0);
		
	}
		NumberofAllocations++;
		if ((NumberofAllocations % 100 ) == 0) 
			printf("We have allocated %d Megabytes. %X\n", NumberofAllocations, MemoryPtr);
		}
		printf("Last location on heap  : %X\n", MemoryPtr);
	int    TopOfStack;
    int    Counter = 0;

    FirstStackLocation = (unsigned long)(&TopOfStack);
    printf("First location on stack: %s\n", 
            commas( (unsigned long)FirstStackLocation  ) );
    RecursiveRoutine( 0 );
}



///////////////////////////////////////////////////////////////////////////
//  This routine is called recursively.  It does no real work but adds
//  a variable to the stack which uses up space onthe stack.
//  It's expected that the program will crash when memory is exhausted.
///////////////////////////////////////////////////////////////////////////

void  RecursiveRoutine( int RecursiveDepth )
{
    char    Temp[ STACK_ALLOC ];
    char    StringTop[32];
    char    StringBottom[32];

    strcpy( StringTop,  commas( (unsigned long)(FirstStackLocation) ) );
    strcpy( StringBottom, commas( (unsigned long)&(Temp[STACK_ALLOC]) ) );
    printf("Iteration = %3d:  Stack Top/Bottom/Bytes: %s  %s  %d\n", 
             RecursiveDepth, StringTop, StringBottom,
             FirstStackLocation - (unsigned long)&(Temp[STACK_ALLOC])  );
    RecursiveDepth++;
    RecursiveRoutine( RecursiveDepth );
}


///////////////////////////////////////////////////////////////////////////
//  The following routines are for formatting only and aren't needed for
//  an understanding of the memory manipulations done above.
///////////////////////////////////////////////////////////////////////////

// This routine converts an unsigned integer into a string with commas.
// You may need to adjust the base and the number of digits between
// commas as given by BASE and GROUP.
// Need space to hold the digits of an unsigned int,
// intervening commas and a null byte. It depends on
// BASE and GROUP above (but logarithmically, not
// as a constant. so we must define it manually here)
///////////////////////////////////////////////////////////////////////////


int prepend(char *, unsigned, char *);
int preprintf(char *, unsigned, char *, ...);

char *commas(unsigned long amount)
    {
    short i;
    short offset = MAXTEXT-1;   /* where the string "starts"  */
    short place;                /* the power of BASE for      */
                                /* current digit              */
    static char text[MAXTEXT];

    for ( i = 0; i < MAXTEXT; i++ )
        text[i] = '\0';
					     
   /* Push digits right-to-left with commas */
   for (place = 0; amount > 0; ++place)
      {
      if (place % GROUP == 0 && place > 0)
         offset = prepend(text,offset,",");
      offset = preprintf(text,offset,"%X",amount % BASE);
      amount /= BASE;
    }
    return (offset >= 0) ? text + offset : NULL;
}
    /* preprint.c: Functions to prepend strings */
    
int prepend(char *buf, unsigned offset, char *new_str)
    {
    int new_len = strlen(new_str);
    int new_start = offset - new_len;
    /* Push a string onto the front of another */
    if (new_start >= 0)
        memcpy(buf+new_start,new_str,new_len);
    
    /* Return new start position (negative if underflowed) */
    return new_start;
}
    
int preprintf(char *buf, unsigned offset, char *format, ...)
    {
    int pos = offset;
    char *temp = malloc(BUFSIZ);
    
    /* Format, then push */
    if (temp)
        {
        va_list args;
        
        va_start(args,format);
        vsprintf(temp,format,args);
        pos = prepend(buf,offset,temp);
        va_end(args);
        free(temp);
    }
    return pos;
}


