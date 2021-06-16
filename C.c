/* function Pointer example
----------------------------------------------------------------------------
*/
typedef void (*nameOfPointer)(int x, char y); //declaration
nameOfPointer pointer = NULL
// you can use it as Argument for function
void function2(nameOfPointer functionWithSameSignature){
	pointer = functionWithSameSignature
}
// calling the funtion
(*pointer)(1,"c");

/* SPI
----------------------------------------------------------------------------
*/
// SPI u have to access on the Send or receive buffer u have access only to dataRegister if u write to it it will send the data to sendbuffer if u read from it it will
//fetch data from the receiving buffer which in return gets the data from shift register 
//you have to send data in order to be able to force Slave to send his response
for(int i = 0 ; i < args[0] ; i++){
	SPI_SendData(SPI2,&dummy_write,1);
	SPI_ReceiveData(SPI2,&id[i],1);
}