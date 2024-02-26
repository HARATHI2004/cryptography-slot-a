#include <stdio.h>
#include <string.h>
#include <ctype.h>
void decryptMessage(const char* ciphertext, const char* mapping) {
    int i;
    int len = strlen(ciphertext);
    char plaintext[1000];
    for (i = 0; i < len; i++) {
        if (isalpha(ciphertext[i])) {
            plaintext[i] = toupper(mapping[ciphertext[i] - 'A']);
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[len] = '\0'; 
	printf("Decrypted message:\n%s\n", plaintext);
}

int main() {
    const char ciphertext[] = "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;]8*;:‡*8†83 \
(88)5*†;46(;88*96*?;8)*‡(;485);5*†2:*‡(;4956*2(5*—4)8¶8* \
;4069285);)6†8)4‡‡;1(‡9;48081;8:8‡1;48†85;4)485†528806*81(‡9;48;(88;4(‡?34;48)4‡;161;:188;‡?;";
    const char mapping[] = "ZNRXWYTSQUVGPFODMHBIAEKLC";

    decryptMessage(ciphertext, mapping);

    return 0;
}

