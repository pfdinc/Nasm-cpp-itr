#include <stdio.h>


void main()
{
	const int Size = 10;
	char TermChar;
	int IntArray[Size];
	int* ptr_IntArray;		// Declares a pointer to an int/
	ptr_IntArray = &IntArray[0]; // Obtains the address the first element of the array1

	char NumberOfInts_Prompt[] = "Please enter number of integers to be entered less than or equal to ";
	char InputNumber_Prompt[] = "Please enter integer ";
	char char_prompt2[] = "enter a number to be searched ";

	int NumberOfInts;	// Numbers of intergers to be read into the program
	int InputNumber;	// Input number
	int i;				// Counter
	int numSearch;

	// Initialize the array to 0.
	for (i = 0; i < 10; i++)
		IntArray[i] = 0;
	// Initialise counter to zero
	i = 0;
	// Read in the number of integers less than 10.
	printf(NumberOfInts_Prompt);
	printf("%d: ", Size);
	scanf("%d", &NumberOfInts);
	scanf("%c", &TermChar);

	__asm
	{
		mov ECX, NumberOfInts			; copy the umber of ints into the ECX registers as counter.
		mov EBX, ptr_IntArray			; move pointer to EBX
			read_char :
		push ECX						; push ECX onto the stach to preserve its contents
	};

	// Read in the input number
	printf(InputNumber_Prompt);
	printf("%d: ", ++i);
	scanf("%d", &InputNumber);
	scanf("%c", &TermChar);

	__asm
	{
			pop ECX						; pop the counter into ECX
			mov EAX, InputNumber		; move input number to EAX
			mov[EBX], EAX				; move EAX to the IntArray via dereferencing[EBX]
			add EBX, 4					; Increment address of EBX to point to next memory address
			loop read_char				; Loop to read_char
			done :
	};
	int location;
	// Print the array with filled numbers

	int arry;
	printf(char_prompt2);

	scanf("%d", &numSearch);

	__asm {

			mov eax, 0					; moved 0 into eax / initialized
			mov ebx, 0					; moved 0 into ebx / initialized
			mov ecx, 0					; moved 0 into ecx / initialized
			mov esi, 0					; moved 0 into esi / initialized

			top :
		cmp esi, NumberOfInts			; compare the esi to the number of integers
			jg exitlooping				; jump if grater to exitlooping
		mov ebx, [IntArray + esi * 4]	; move[IntArray + esi * 4] into the ebx registers
			mov ecx, numSearch			; move the your number search into the ecx
			inc esi						; increment the esi by 1
			cmp ebx, ecx				; compare ebx with ecx
			jl top						; if ebx is larger then jump to top
			sub esi, 1					; subtract 1 from edi
			mov location, esi			; move esi into location
			mov arry, ebx				;move ebx into arry


	}

	printf("The numbers in your array:");
	for (i = 0; i < NumberOfInts; i++) {
		printf("%d ", IntArray[i]);
	}
	// new line
	printf("\n");
	__asm {

	exitlooping:
	}

	//prints the location
	printf("\nthe location of the array is %d \n", location);
	//prints the serched array
	printf("\nNumber in the array grater or equal to your search is  %d \n", arry);



	getchar();

}