/* Videoaula 9 -  22:38
  * Implementando a aplicação de verificar palíndrome
  */

 #include "stack.h"
 #include "queue.h"
 #include <iostream>

 using namespace std;

 int main(){
     bool isPalindrome = true;
     ItemType letterInput;
     ItemType letterQueue;
     ItemType letterStack;

     Queue thisQueue;
     Stack thisStack;

    // Coleta dos dados - input de texto para verificação de palíndrome
     cout << "Insert a strint to palindrome verify (press return to exit): ";
     cin.get(letterInput);
     while (letterInput != '\n')
     {
        thisQueue.enqueue(letterInput);
        thisStack.push(letterInput);
        cin.get(letterInput);
     }
     
     cout << "Checking this string, wait please..." << endl;

     while (isPalindrome && !thisQueue.isEmpty()){
         letterQueue = thisQueue.dequeue();
         letterStack = thisStack.pop();
         isPalindrome = (letterQueue==letterStack);
     }

     if (isPalindrome){
         cout << "That's right, a string is a palindrome!!" << endl;
     } else {
         cout << "Owow... isn't a palindrome yeat!" << endl;
     }

     return 0;
 }