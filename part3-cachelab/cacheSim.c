#include "cacheSim.h"

// In this question, we will assume DRAM will take a 4-byte values starting from 0 to 
void init_DRAM()
{
	unsigned int i=0;
	DRAM = malloc(sizeof(char) * DRAM_SIZE);
	for(i=0;i<DRAM_SIZE/4;i++)
	{
		*((unsigned int*)DRAM+i) = i;
	}
}

void printCache()
{
	int i,j,k;
	printf("===== L1 Cache Content =====\n");
	for(i=0;i<2;i++)
	{
		printf("Set %d :", i);
		for(j=0;j<2;j++)
		{
			printf(" {(TAG: 0x%x)", (unsigned int)(L1_cache[i][j].tag));
			for(k=0;k<16;k++)
				printf(" 0x%x,", (unsigned int)(L1_cache[i][j].data[k]));
			printf(" |");
		}
		printf("\n");
	}
	printf("===== L2 Cache Content =====\n");
	for(i=0;i<4;i++)
	{
		printf("Set %d :", i);
		for(j=0;j<4;j++)
		{
			printf(" {(TAG: 0x%x)", (unsigned int)(L2_cache[i][j].tag));
			for(k=0;k<16;k++)
				printf(" 0x%x,", (unsigned int)(L2_cache[i][j].data[k]));
			printf(" |");
		}
		printf("\n");
	}
}

//  part 2

u_int32_t read_fifo(u_int32_t address){
//init values
unsigned int l1Set = getL1SetID(address);
unsigned int l2Set = getL2setID(address);
unsigned int l1Tag = getL1Tag(address);
unsigned int l2Tag = getL2Tag(address);

//tracking hits with a variable, -1 is the number used because a hit would never be in the negatives

int l1_hit = -1;
int l2_hit = -1;

// Cheking for the hit on L1 
for (int i = 0; i < 2; i++);
	if (L1_cache[l1Set][i].tag == l1Tag){
		l1_hit = i;
		break;
	}

//if l1 miss
if (l1_hit == -1){
	for (int i = 0; i < 4; i++){
		if (L2_cache[l2_set][i].tag == l2_tag){
			l2_hit = i;
			break;
		}
	}
}

//if l2 miss
/*
this means that data isnt in either l1 or 2
meand that we need to access DRAM.

bBUUT L2 might be full
we have to kick someone out first
the oldest piece of data
just iterate thru, but now start from 0 so l2_hit will actually not be a hti but it will be set to 0 so we can use
*/

l2_hit = 0;
u_int32_t min_time = L2_cache[l2_set][0].

return 0;
}



//part 1



int L1lookup(u_int32_t address){
//use the functions I wrote below here :O 
unsigned int SetId = getL1SetID(address);
unsigned int tag = getL1Tag(address);
// then do some i j loop thru all set row
// only got 2 sets so the break condition for loop it > 2 (i.e 0 and 1)
for (int i = 0; < 2; i++) {
	if (L1_cache[SetId][i].tag == tag){
		// checks in a "grid" for ID(row) and the current iteration i(column)
		//took a while to find tag lol
		return 1;
		//means hit
	} 
}
return 0;
//means miss
}

int L2lookup(u_int32_t address){
//exact same as the L1 but just 4 columns instead of 2
unsigned int SetId = getL2SetID(address);
unsigned int tag = getL2Tag(address);

for (int i = 0; < 4; i++) {
	if (L1_cache[SetId][i].tag == tag){

		return 1;
		//hit
	} 
}

return 0;
//miss :C 
}


unsigned int getL1SetID(u_int32_t address){
return (address >> 4) & 1;
//this returns the set id that is the largest bit, 
// to make sure that we only return that one bit, we use AND to filter for that -now- leftmost bit.
}

unsigned int getL2SetID(u_int32_t address){
return (address >> 4) & 3;
// same thing here but with different shifting amounts because we want two bits and filtering two bits.
}

unsigned int getL1Tag(u_int32_t address){
return address >> 5;
// this is the set address shifted leftmost, dont need the and because its unsigned and theres nothing before the tag bits (padded 0s)
}

unsigned int getL2Tag(u_int32_t address){
return address >> 6;
// same Idea as the one above!!
}


void write(u_int32_t address, u_int32_t data)
{
///// REPLACE THIS /////
	read_fifo(address);
return;
}


int main()
{
	init_DRAM();
	cacheAccess buffer;
	int timeTaken=0;
	FILE *trace = fopen("input.trace","r");
	int L1hit = 0;
	int L2hit = 0;
	cycles = 0;
	while(!feof(trace))
	{
		fscanf(trace,"%d %x %x", &buffer.readWrite, &buffer.address, &buffer.data);
		printf("Processing the request for [R/W] = %d, Address = %x, data = %x\n", buffer.readWrite, buffer.address, buffer.data);

		// Checking whether the current access is a hit or miss so that we can advance time correctly
		if(L1lookup(buffer.address))// Cache hit
		{
			timeTaken = 1;
			L1hit++;
		}
		else if(L2lookup(buffer.address))// L2 Cache Hit
		{
			L2hit++;
			timeTaken = 5;
		}
		else timeTaken = 50;
		if (buffer.readWrite) write(buffer.address, buffer.data);
		else read_fifo(buffer.address);
		cycles+=timeTaken;
	}
	printCache();
	printf("Total cycles used = %ld\nL1 hits = %d, L2 hits = %d", cycles, L1hit, L2hit);
	fclose(trace);
	free(DRAM);
	return 0;
}




