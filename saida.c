// --- variaveis do LED ---
int led10 = 10;
int led11 = 11;
int led12 = 12;
int led13 = 13;

// --- variaveis auxiliares ---
char w;
char x;
char y;

char memoria[300]; // vetor que armazena input
int listagem[100]; // vetor que armazena a resposta
int contador = 1; // contar

// --- inicialização ---
void setup() {               
  pinMode(led10, OUTPUT);
  pinMode(led11, OUTPUT);
  pinMode(led12, OUTPUT);
  pinMode(led13, OUTPUT);
  Serial.begin(9600);
}

	
// --- loop para todas as operações ---
void loop(){
  
  // --- se tem alguma memoria para ser lida ---
  if (Serial.available() > 2) {
      memoria[1] = Serial.read(); // ler input A
      memoria[2] = Serial.read(); // ler input B
      memoria[3] = Serial.read(); // ler input da operação
    
    	// --- auxiliares ---
    	w = memoria[1];
        x = memoria[2];
        y = memoria[3];
    	
       // --- pega de 3 em 3 ---
       memoria[contador * 3 + 1] = w;
       memoria[contador * 3 + 2] = x;
       memoria[contador * 3 + 3] = y; 
   	
//-------------------- Funções --------------------
    
    //Operação A'
    if(memoria[3] == '0'){
      int i = 0;
      int vet_bin[4];

      i = converteInteiro(memoria[1]);
      i = inverteInteiro()
      listagem[contador]= inverteInteiro(i);
      
      //Passo o decimal para binario
      for(int k = 0 ; k<=3 ; k++){
      	vet_bin[k] = i%2;
        i = i/2;
       }
      
      //Nego o binario
      for(int k = 0 ; k<=3 ; k++){
        if(vet_bin[k] == 0){
          vet_bin[k] = 1;
        }
        else{
          vet_bin[k] = 0;
        }
      }
      
      //Led vermelho
      if(vet_bin[3] == 1){
       	digitalWrite(led13, HIGH); 
      }
      else{
        digitalWrite(led13, LOW);
      }
      //Led Amarelo
	  if(vet_bin[2] == 1){
       	digitalWrite(led12, HIGH); 
      }
      else{
        digitalWrite(led12, LOW);
      }
      //Led Verde
	  if(vet_bin[1] == 1){
       	digitalWrite(led11, HIGH); 
      }
      else{
        digitalWrite(led11, LOW);
      }
      //Led Azul
	  if(vet_bin[0] == 1){
       	digitalWrite(led10, HIGH); 
      }
      else{
        digitalWrite(led10, LOW);
      }
    }
    
    
    //Operação (A+B)'
    else if(memoria[3] == '1'){

      
      int vet_bin[4];// vetor que armazena o binario
      
      // --- transforma char em int ---
      int i = converteInteiro(memoria[1]);
      int j = converteInteiro(memoria[2]);

      int resultado = portaor(i, j);
      listagem[contador] = inverteInteiro(resultado); // inverte so no resultado final

      // --- transforma o resultado em binario ---
      for(int k = 3 ; k>=0 ; k--){
        vet_bin[k] = resultado%2;
        resultado = resultado/2;
      }
      
      // --- negar o binario (inverter) ---
      for(int k = 3 ; k>=0 ; k--){
        if(vet_bin[k] == 0){
          vet_bin[k] = 1;
        }
        else{
          vet_bin[k] = 0;
        }
      }

      //Led vermelho
      if(vet_bin[0] == 1){
        digitalWrite(led13, HIGH); 
      }
      else{
        digitalWrite(led13, LOW);
      }
      //Led Amarelo
      if(vet_bin[1] == 1){
        digitalWrite(led12, HIGH); 
      }
      else{
        digitalWrite(led12, LOW);
      }
      //Led Verde
      if(vet_bin[2] == 1){
        digitalWrite(led11, HIGH); 
      }
      else{
        digitalWrite(led11, LOW);
      }
      //Led Azul
      if(vet_bin[3] == 1){
        digitalWrite(led10, HIGH); 
      }
      else{
        digitalWrite(led10, LOW);
      }
    }


    //Operação A'B
    else if(memoria[3] == '2'){

      int vet_bin[4];

      int i = converteInteiro(memoria[1]);
      int j = converteInteiro(memoria[2]);
      i = inverteInteiro(i);// para negar o numero (inverter)

      int resultado = portaAnd(i, j);
      listagem[contador] = resultado; 

      for(int k = 0 ; k<=3 ; k++){
        vet_bin[k] = resultado%2;
        resultado = resultado/2;
      }


      //Led vermelho
      if(vet_bin[3] == 1){
        digitalWrite(led13, HIGH); 
      }
      else{
        digitalWrite(led13, LOW);
      }
      //Led Amarelo
      if(vet_bin[2] == 1){
        digitalWrite(led12, HIGH); 
      }
      else{
        digitalWrite(led12, LOW);
      }
      //Led Verde
      if(vet_bin[1] == 1){
        digitalWrite(led11, HIGH); 
      }
      else{
        digitalWrite(led11, LOW);
      }
      //Led Azul
      if(vet_bin[0] == 1){
        digitalWrite(led10, HIGH); 
      }
      else{
        digitalWrite(led10, LOW);
      }
    }   


    //Operação 0 Lógico
    else if(memoria[3] == '3'){

      //Led vermelho
      digitalWrite(led13, LOW);
      //Led Amarelo
      digitalWrite(led12, LOW);
      //Led Verde
      digitalWrite(led11, LOW);
      //Led Azul
      digitalWrite(led10, LOW);
      
      listagem[contador] = 0; 
    }
    
    
    
    //Operação (AB)'
    else if(memoria[3] == '4'){

      int vet_bin[4];
      int i = converteInteiro(memoria[1]);
      int j = converteInteiro(memoria[2]);

      int resultado = portaAnd(i, j);
      listagem[contador] = inverteInteiro(resultado); 

      for(int k = 0 ; k<=3 ; k++){
        vet_bin[k] = resultado%2;
        resultado = resultado/2;
      }

      for(int k = 0 ; k<=3 ; k++){
        if(vet_bin[k] == 0){
          vet_bin[k] = 1;
        }
        else{
          vet_bin[k] = 0;
        }
      }
      
      //Led vermelho
      if(vet_bin[3] == 1){
        digitalWrite(led13, HIGH); 
      }
      else{
        digitalWrite(led13, LOW);
      }
      //Led Amarelo
      if(vet_bin[2] == 1){
        digitalWrite(led12, HIGH); 
      }
      else{
        digitalWrite(led12, LOW);
      }
      //Led Verde
      if(vet_bin[1] == 1){
        digitalWrite(led11, HIGH); 
      }
      else{
        digitalWrite(led11, LOW);
      }
      //Led Azul
      if(vet_bin[0] == 1){
        digitalWrite(led10, HIGH); 
      }
      else{
        digitalWrite(led10, LOW);
      }
    }
    	
    
    //Operação B'
    else if(memoria[3] == '5'){
      int j = 0;
      int vet_bin[4];

      j = converteInteiro(memoria[2]);
      
      listagem[contador] = inverteInteiro(j); 

      //Passo o decimal para binario
      for(int k = 0 ; k<=3 ; k++){
        vet_bin[k] = j%2;
        j = j/2;
      }

      //Nego o binario
      for(int k = 0 ; k<=3 ; k++){
        if(vet_bin[k] == 0){
          vet_bin[k] = 1;
        }
        else{
          vet_bin[k] = 0;
        }
      }
      
      //Led vermelho
      if(vet_bin[3] == 1){
        digitalWrite(led13, HIGH); 
      }
      else{
        digitalWrite(led13, LOW);
      }
      //Led Amarelo
      if(vet_bin[2] == 1){
        digitalWrite(led12, HIGH); 
      }
      else{
        digitalWrite(led12, LOW);
      }
      //Led Verde
      if(vet_bin[1] == 1){
        digitalWrite(led11, HIGH); 
      }
      else{
        digitalWrite(led11, LOW);
      }
      //Led Azul
      if(vet_bin[0] == 1){
        digitalWrite(led10, HIGH); 
      }
      else{
        digitalWrite(led10, LOW);
      }
    }
    
    //Operação A⊕B 
    else if(memoria[3] == '6'){

      int vet_bin[4];
      int i = converteInteiro(memoria[1]);
      int j = converteInteiro(memoria[2]);

      int resultado = portaxor(i, j);
      listagem[contador] = resultado; 

      for(int k = 0 ; k<=3 ; k++){
        vet_bin[k] = resultado%2;
        resultado = resultado/2;
      }
      
      //Led vermelho
      if(vet_bin[3] == 1){
        digitalWrite(led13, HIGH); 
      }
      else{
        digitalWrite(led13, LOW);
      }
      //Led Amarelo
      if(vet_bin[2] == 1){
        digitalWrite(led12, HIGH); 
      }
      else{
        digitalWrite(led12, LOW);
      }
      //Led Verde
      if(vet_bin[1] == 1){
        digitalWrite(led11, HIGH); 
      }
      else{
        digitalWrite(led11, LOW);
      }
      //Led Azul
      if(vet_bin[0] == 1){
        digitalWrite(led10, HIGH); 
      }
      else{
        digitalWrite(led10, LOW);
      }
     }
    
    //Operação AB'
    else if(memoria[3] == '7'){

      int vet_bin[4];
      int i = converteInteiro(memoria[1]);
      int j = converteInteiro(memoria[2]);
      j = inverteInteiro(j);

      int resultado = portaAnd(i, j);
      listagem[contador] = resultado; 

      for(int k = 0 ; k<=3 ; k++){
        vet_bin[k] = resultado%2;
        resultado = resultado/2;
      }
      
       //Led vermelho
      if(vet_bin[3] == 1){
        digitalWrite(led13, HIGH); 
      }
      else{
        digitalWrite(led13, LOW);
      }
      //Led Amarelo
      if(vet_bin[2] == 1){
        digitalWrite(led12, HIGH); 
      }
      else{
        digitalWrite(led12, LOW);
      }
      //Led Verde
      if(vet_bin[1] == 1){
        digitalWrite(led11, HIGH); 
      }
      else{
        digitalWrite(led11, LOW);
      }
      //Led Azul
      if(vet_bin[0] == 1){
        digitalWrite(led10, HIGH); 
      }
      else{
        digitalWrite(led10, LOW);
      }
    }
    
    
    //Operação A'+B
    else if(memoria[3] == '8'){

      int vet_bin[4];

      int i = converteInteiro(memoria[1]);
      int j = converteInteiro(memoria[2]);
      i = inverteInteiro(i);

      int resultado = portaor(i, j);
      listagem[contador] = resultado; 

      for(int k = 0 ; k<=3 ; k++){
        vet_bin[k] = resultado%2;
        resultado = resultado/2;
      }
      
      //Led vermelho
      if(vet_bin[3] == 1){
        digitalWrite(led13, HIGH); 
      }
      else{
        digitalWrite(led13, LOW);
      }
      //Led Amarelo
      if(vet_bin[2] == 1){
        digitalWrite(led12, HIGH); 
      }
      else{
        digitalWrite(led12, LOW);
      }
      //Led Verde
      if(vet_bin[1] == 1){
        digitalWrite(led11, HIGH); 
      }
      else{
        digitalWrite(led11, LOW);
      }
      //Led Azul
      if(vet_bin[0] == 1){
        digitalWrite(led10, HIGH); 
      }
      else{
        digitalWrite(led10, LOW);
      }
    }
    
    
    //Operação (A⊕B)'
    else if(memoria[3] == '9'){

      int vet_bin[4];
      int i = converteInteiro(memoria[1]);
      int j = converteInteiro(memoria[2]);

      int resultado = portaxor(i, j);
      listagem[contador] = inverteInteiro(resultado); 

      for(int k = 0 ; k<=3 ; k++){
        vet_bin[k] = resultado%2;
        resultado = resultado/2;
      }

      for(int k = 0 ; k<=3 ; k++){
        if(vet_bin[k] == 0){
          vet_bin[k] = 1;
        }
        else{
          vet_bin[k] = 0;
        }
      }  
      
      //Led vermelho
      if(vet_bin[3] == 1){
        digitalWrite(led13, HIGH); 
      }
      else{
        digitalWrite(led13, LOW);
      }
      //Led Amarelo
      if(vet_bin[2] == 1){
        digitalWrite(led12, HIGH); 
      }
      else{
        digitalWrite(led12, LOW);
      }
      //Led Verde
      if(vet_bin[1] == 1){
        digitalWrite(led11, HIGH); 
      }
      else{
        digitalWrite(led11, LOW);
      }
      //Led Azul
      if(vet_bin[0] == 1){
        digitalWrite(led10, HIGH); 
      }
      else{
        digitalWrite(led10, LOW);
      }
    }
    
    
    //Operação B
    else if(memoria[3] == 'a' || memoria[3] == 'A'){

      int vet_bin[4];
      int j = converteInteiro(memoria[2]);
      listagem[contador] = j; 

      for(int k = 0 ; k<=3 ; k++){
        vet_bin[k] = j%2;
        j = j/2;
      }
      
      //Led vermelho
      if(vet_bin[3] == 1){
        digitalWrite(led13, HIGH); 
      }
      else{
        digitalWrite(led13, LOW);
      }
      //Led Amarelo
      if(vet_bin[2] == 1){
        digitalWrite(led12, HIGH); 
      }
      else{
        digitalWrite(led12, LOW);
      }
      //Led Verde
      if(vet_bin[1] == 1){
        digitalWrite(led11, HIGH); 
      }
      else{
        digitalWrite(led11, LOW);
      }
      //Led Azul
      if(vet_bin[0] == 1){
        digitalWrite(led10, HIGH); 
      }
      else{
        digitalWrite(led10, LOW);
      }
    }
    
    //Operação AB
    else if(memoria[3] == 'b' || memoria[3] == 'B'){

      int vet_bin[4];

      int i = converteInteiro(memoria[1]);
      int j = converteInteiro(memoria[2]);

      int resultado = portaAnd(i, j);
      listagem[contador] = resultado; 

      for(int k = 0 ; k<=3 ; k++){
        vet_bin[k] = resultado%2;
        resultado = resultado/2;
      }
	  //Led vermelho
      if(vet_bin[3] == 1){
        digitalWrite(led13, HIGH); 
      }
      else{
        digitalWrite(led13, LOW);
      }
      //Led Amarelo
      if(vet_bin[2] == 1){
        digitalWrite(led12, HIGH); 
      }
      else{
        digitalWrite(led12, LOW);
      }
      //Led Verde
      if(vet_bin[1] == 1){
        digitalWrite(led11, HIGH); 
      }
      else{
        digitalWrite(led11, LOW);
      }
      //Led Azul
      if(vet_bin[0] == 1){
        digitalWrite(led10, HIGH); 
      }
      else{
        digitalWrite(led10, LOW);
      }
    }
    
    
    //Operação 1 Lógica
    else if(memoria[3] == 'c' || memoria[3] == 'C'){
		//Led vermelho
        digitalWrite(led13, HIGH); 
      	//Led Amarelo
      	digitalWrite(led12, HIGH); 
      	//Led Verde
      	digitalWrite(led11, HIGH); 
      	//Led Azul
      	digitalWrite(led10, HIGH);
      listagem[contador] = 15; 
    }
    
    
    //Operação A+B'
    else if(memoria[3] == 'd' || memoria[3] == 'D'){

      int vet_bin[4];

      int i = converteInteiro(memoria[1]);
      int j = converteInteiro(memoria[2]);
      j = inverteInteiro(j);

      int resultado = portaor(i, j);
      listagem[contador] = resultado; 

      for(int k = 0 ; k<=3 ; k++){
        vet_bin[k] = resultado%2;
        resultado = resultado/2;
      }
      //Led vermelho
      if(vet_bin[3] == 1){
        digitalWrite(led13, HIGH); 
      }
      else{
        digitalWrite(led13, LOW);
      }
      //Led Amarelo
      if(vet_bin[2] == 1){
        digitalWrite(led12, HIGH); 
      }
      else{
        digitalWrite(led12, LOW);
      }
      //Led Verde
      if(vet_bin[1] == 1){
        digitalWrite(led11, HIGH); 
      }
      else{
        digitalWrite(led11, LOW);
      }
      //Led Azul
      if(vet_bin[0] == 1){
        digitalWrite(led10, HIGH); 
      }
      else{
        digitalWrite(led10, LOW);
      }
    }
    
    
    //Operação A+B
    else if(memoria[3] == 'e' || memoria[3] == 'E'){

      int vet_bin[4];

      int i = converteInteiro(memoria[1]);
      int j = converteInteiro(memoria[2]);

      int resultado = portaor(i, j);
      listagem[contador] = resultado; 
      

      for(int k = 0 ; k<=3 ; k++){
        vet_bin[k] = resultado%2;
        resultado = resultado/2;
      } 
      //Led vermelho
      if(vet_bin[3] == 1){
        digitalWrite(led13, HIGH); 
      }
      else{
        digitalWrite(led13, LOW);
      }
      //Led Amarelo
      if(vet_bin[2] == 1){
        digitalWrite(led12, HIGH); 
      }
      else{
        digitalWrite(led12, LOW);
      }
      //Led Verde
      if(vet_bin[1] == 1){
        digitalWrite(led11, HIGH); 
      }
      else{
        digitalWrite(led11, LOW);
      }
      //Led Azul
      if(vet_bin[0] == 1){
        digitalWrite(led10, HIGH); 
      }
      else{
        digitalWrite(led10, LOW);
      }
    }
    
    //Operação A
    else if(memoria[3] == 'f' || memoria[3] == 'F'){

      int vet_bin[4];

      int i = converteInteiro(memoria[1]);
      listagem[contador] = i; 

      for(int k = 0 ; k<=3 ; k++){
        vet_bin[k] = i%2;
        i = i/2;
      }

      for(int k = 3 ; k>= 0 ; k--){
        printf("%i", vet_bin[k]);
      }
      //Led vermelho
      if(vet_bin[3] == 1){
        digitalWrite(led13, HIGH); 
      }
      else{
        digitalWrite(led13, LOW);
      }
      //Led Amarelo
      if(vet_bin[2] == 1){
        digitalWrite(led12, HIGH); 
      }
      else{
        digitalWrite(led12, LOW);
      }
      //Led Verde
      if(vet_bin[1] == 1){
        digitalWrite(led11, HIGH); 
      }
      else{
        digitalWrite(led11, LOW);
      }
      //Led Azul
      if(vet_bin[0] == 1){
        digitalWrite(led10, HIGH); 
      }
      else{
        digitalWrite(led10, LOW);
      }
    }
    
    Serial.print("->| ");
    Serial.print(contador+3);
    Serial.print(" | ");
    Serial.print(listagem[contador], HEX);
    Serial.print(" | ");
    Serial.print(memoria[2]);
    Serial.print(" | ");
    Serial.print(memoria[3]);
    Serial.print(" | ");
    for(int m=1 ; m<=contador ; m++){
      Serial.print(memoria[m * 3 + 1]);
      Serial.print(memoria[m * 3 + 2]);
      Serial.print(memoria[m * 3 + 3]);
      Serial.print(" | ");
    }
    Serial.println();
    
    contador++;
    
    
  }
}
  

//------------------------ Funções ------------------------
int converteInteiro(char s){
    int i = 0;

    if(s >= 48 && s <= 57){
        i = s - 48;
    } 
  	else if(s>=97 && s<=122){
    	i = s-87;
  }
    else{
        i = s - 55;
    }
    return i;
}

int inverteInteiro(int i){
    int resultado = 15 -i;
    return resultado;
}


int portaAnd(int a, int b){
    return(a&b);
}

int portaor(int a, int b){
    return(a|b);
}

int portaxor(int a, int b){
  return(a^b);
}
