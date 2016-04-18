void f(void); 
void g(void);
 
 int main(void) {
   f();
 
   return 0;
 }
 
 void f(void) {
   g();
 }
 
 void g(void) {
   f();  
 }
