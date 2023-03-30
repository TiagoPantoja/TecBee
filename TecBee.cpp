/*Incluindo display de LCD */
/* Incluindo sensor de temperatura e umidade DHT11 */
#include <LiquidCrystal.h>
#include "DHT.h"

/* Indicando que é o DHT modelo 11, que ele está no pino 10 e inicializando no código */
#define DHTPIN 10
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

/* Criando as funções principais, que vão monitorar temperatura e umidade da caixa de abelhas */
void funcaoMonitora();
void monitoraTemperatura(float valorTemp);
void monitoraUmidade(float valorUmid);

/* Criando função que vai mostrar os valores recebidos no display de LCD */
void mostraValores(float valorTemp, float valorUmid);

/* Criando funções que vão realizar o controle da temperatura dentro da caixa de abelhas */
void funcaoControla();
void controlaTemperatura();

/* Criando função para realizar o controle por meio de botões integrados */
void botaoDirecional();
float botaoAumentaDiminui(float dados);

/* Inicializando o número das portas digitais do Arduino */
int dadosSensores[200];
int botaoAumenta = 8;
int botaoDiminui = 9;
int botaoSeleciona = 10;
int botaoVolta = 11;
int ledVermelho = 14;
int ledVerde = 15;
int ledAzul = 16;
int buzzer = 17;

/* Inicializando o display LCD, do mesmo jeito que foi inicializado o sensor DHT 11 */
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

/* Criando variáveis relacionadas a temperatura, umidade, botões e leitura */
float temperaturaMinima = 0.0;
float temperaturaMaxima = 0.0;
float umidadeMinima = 0.0;
float umidadeMaxima = 0.0;
int cursorColuna = 0;
int cursorLinha = 0;
float leituraTemperatura = 0.0;
float leituraUmidade = 0.0;

/* Definindo o cursor para auxiliar na leitura e exibição dos dados no display LCD */
byte cursor[8] = {
    B00000,
    B00000,
    B00110,
    B11111,
    B00110,
    B00000,
    B00000,
};

/* Chamando a função padrão do Arduino para rodar o código uma vez */
void setup() {
    // Adicionando valores no display LCD
    lcd.createChar(0, cursor);
    lcd.begin(16,2);
}

/* Adicionando leds e o buzzer no circuito */
    pinMode(ledVermelho, OUTPUT);
