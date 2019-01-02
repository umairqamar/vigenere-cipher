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
 
    //Create new key equal to size of text
    for(i = 0, j = 0; i < textLength; ++i, ++j){
        if(j == keyLength)
            j = 0;
 
        newKey[i] = key[j];
    }
 
    newKey[i] = '\0';
 
    //encryption
    for(i = 0; i < textLength; ++i)
        encryptedText[i] = ((text[i] + newKey[i]) % 26) + 'A';
    encryptedText[i] = '\0';
 
    //decryption
    for(i = 0; i < textLength; ++i)
        decryptedText[i] = (((encryptedText[i] - newKey[i]) + 26) % 26) + 'A';
 
    decryptedText[i] = '\0';
 
    printf("Original Message: %s", text);
    printf("\nKey: %s", key);
    printf("\nNew Generated Key: %s", newKey);
    printf("\nEncrypted Message: %s", encryptedText);
    printf("\nDecrypted Message: %s", decryptedText);
    
 	return 0;
}


