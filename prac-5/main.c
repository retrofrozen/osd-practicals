 #include <stdio.h>

void main() {
	int buffer[10],bufsize = 10,in = 0,out = 0,produce,consume,choice = 0;
	while (choice != 3) {
		printf("1. Produce \t 2. Consume \t 3. Exit\n");
		printf("Enter your Choice : ");
		scanf("%d", &choice);
		printf("\n");

		switch (choice) {
			case 1: if ((in+1)%bufsize == out) {
						printf("Buffer is Full\n");
					} else {
						printf("Enter the value : \n");
						scanf("%d", &produce);
						printf("\n");
						buffer[in] = produce;
						in = (in+1)%bufsize;
					}	
					break;

			case 2: if 	(in == out) {
						printf("Buffer is Empty!!\n");
					} else {
						consume = buffer[out];
						// Can consume only 10 at a time
						printf("The Consumed Value is %d\n", consume);
						out = (out+1)%bufsize;
					}
					break;
 		}
	}
}