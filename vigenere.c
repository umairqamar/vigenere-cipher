#include<stdio.h>
#include<string.h>

int main(){
	char text[] = "THECRAZYPROGRAMMER";
    char key[] = "HELLO";
    int textLength = strlen(text);
    int keyLength = strlen(key);
	int i, j; //counters
    char newKey[textLength];
	char encryptedText[textLength];
	char decryptedText[textLength];
	int option;
    
    printf("Vigenere Cipher\n\nPlease choose from following options""\n1. Encrypt\n2. Decrypt\nYour Option: ");
	scanf("%d", &option);
	
	switch(option) {
		case 1:
			printf("Enter text to encrypt: ");
			scanf("%s", &text);
			printf("Enter Key: ");
			scanf("%d", &key);
			//Create new key equal to size of text
    		for(i = 0, j = 0; i < textLength; ++i, ++j){
	        	if(j == keyLength)
	            	j = 0;
	        	newKey[i] = key[j];
    		}
    		newKey[i] = '\0';
    		 //encryption
    		for(i = 0; i < textLength; ++i){
    			encryptedText[i] = ((text[i] + newKey[i]) % 26) + 'A';
			}
       		encryptedText[i] = '\0';
    		printf("Encrypted Text: %s", encryptedText);
      		break;
		case 2:
			printf("Enter text to decrypt: ");
			scanf("%s", &encryptedText);
			printf("Enter Key: ");
			scanf("%d", &key);
      		//Create new key equal to size of text
    		for(i = 0, j = 0; i < textLength; ++i, ++j){
	        	if(j == keyLength)
	            	j = 0;
	        	newKey[i] = key[j];
    		}
    		newKey[i] = '\0';
    		//Decryption
    		for(i = 0; i < textLength; ++i){
    			decryptedText[i] = (((encryptedText[i] - newKey[i]) + 26) % 26) + 'A';
			}
        	decryptedText[i] = '\0';
        	printf("\nDecrypted Message: %s", decryptedText);
     		break;
	   default:
   			printf("Wrong Option Selected");
	}
    return 0;
    
    
    //Check if the Text is alphabetical
    for (i=0;i<textLength;i++){
		if(!isalpha(text[i])){
			printf("You have non-alphabetical chars in Text \n");
			return 1;
		}
	}
	//Check if key is alphabetical
	for (i=0;i<keyLength;i++){
		if(!isalpha(key[i])){
			printf("You have non-alphabetical chars in Key \n");
			return 1;
		}
	}
	
    
   
    //decryption
    
 
    printf("Original Message: %s", text);
    printf("\nKey: %s", key);
    printf("\nNew Generated Key: %s", newKey);
    printf("\nEncrypted Message: %s", encryptedText);
    
    
 	return 0;
}



