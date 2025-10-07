# 🚌 Lisbon Bus Voyage

**Lisbon Bus Voyage** é uma aplicação desenvolvida em **C**, concebida para simular um sistema de **bilheteira de autocarros**. Permite ao utilizador comprar bilhetes, consultar horários, escolher destinos e gerir lugares disponíveis em cada viagem.

📅 **Versão:** 1.0  
🧑‍💻 **Autor:** Rodrigo Faria Rocha  
📍 **Projeto de 1º Ano – C Programming**

---

## 📚 Índice

- [🧠 Descrição Geral](#-descrição-geral)
- [⚙️ Tecnologias Utilizadas](#-tecnologias-utilizadas)
- [🗃️ Estrutura do Projeto](#-estrutura-do-projeto)
- [🧭 Funcionalidades Principais](#-funcionalidades-principais)
- [🧪 Requisitos do Sistema](#-requisitos-do-sistema)
- [👨‍💻 Instruções para Programadores](#-instruções-para-programadores)
- [🖼️ Exemplo de Execução](#-exemplo-de-execução)
- [📈 Melhorias Futuras](#-melhorias-futuras)
- [📌 Considerações Finais](#-considerações-finais)

---

## 🧠 Descrição Geral

Lisbon Bus Voyage permite ao utilizador:

* Consultar horários e destinos disponíveis  
* Escolher destinos e número de bilhetes  
* Verificar disponibilidade de lugares  
* Comprar bilhetes com cálculo automático de preços  
* Visualizar informações detalhadas de cada viagem  

### Destaque:

> Um projeto educativo que consolida fundamentos de programação em C, lógica, estruturas de dados e modularidade.

---

## ⚙️ Tecnologias Utilizadas

* Linguagem **C**  
* Compilador **GCC**  
* Ambiente de desenvolvimento: **Code::Blocks / Visual Studio Code**  
* Estruturas básicas: arrays, ciclos, funções e condicionais  

---

## 🗃️ Estrutura do Projeto

Organizado em ficheiros modulares:

* `main.c` – Menu principal e execução  
* `funcoes.c` – Funções auxiliares (gestão de bilhetes, preços, lugares)  
* `funcoes.h` – Cabeçalho com protótipos das funções  
* `README.md` – Documentação do projeto  
* `dados.txt` – (Opcional) Dados de exemplo de lugares e viagens  

---

## 🧭 Funcionalidades Principais

* 🕒 Consulta de horários e destinos  
* 🎫 Compra de bilhetes com validação de lugares  
* 💺 Gestão de lugares disponíveis por autocarro  
* 💰 Cálculo automático do preço da viagem  
* 🔄 Possibilidade de reiniciar o processo e ver viagens disponíveis  

---

## 🧪 Requisitos do Sistema

* Sistema Operativo: **Windows / Linux**  
* Compilador de C (GCC recomendado)  
* Ambiente de desenvolvimento compatível com C  
* Espaço em disco: aproximadamente **10 MB**

---

## 👨‍💻 Instruções para Programadores
1. Clonar o repositório:
git clone https://github.com/rodrigorocha/LisbonBusVoyage.git

3. Abrir o projeto
Abrir o projeto no Code::Blocks ou outro IDE compatível com C.

5. Compilar o programa:
gcc main.c funcoes.c -o LisbonBusVoyage

7. Executar:
main.exe

9. Explorar
Navega pelo menu e testa todas as funcionalidades disponíveis.
- 🖼️ Exemplo de Execução

<img width="884" height="519" alt="image" src="https://github.com/user-attachments/assets/c0306801-37e3-4495-8403-01ec6b0bc24b" />
<img width="863" height="512" alt="image" src="https://github.com/user-attachments/assets/b4658a09-e0ca-4309-aabe-2bc10fefd165" />
<img width="920" height="513" alt="image" src="https://github.com/user-attachments/assets/3bd015f2-e983-4877-920a-e561c021ec0b" />
<img width="653" height="477" alt="image" src="https://github.com/user-attachments/assets/ea151f9d-db72-4b41-a3ce-5dfe93f36f42" />

## 📈 Melhorias Futuras
✅ Adicionar suporte a mais destinos e horários
✅ Guardar histórico de compras dos utilizadores
✅ Interface gráfica simples com GTK ou ncurses
✅ Implementar persistência de dados mais avançada com ficheiros binários

## 📌 Considerações Finais
Lisbon Bus Voyage é um projeto educativo que combina lógica de programação, modularidade e gestão de dados.
Permite ao utilizador interagir com um sistema realista de bilheteira, ao mesmo tempo que consolida conhecimentos fundamentais em linguagem C.
Aprender programação é mais eficaz quando aplicamos os conceitos em projetos reais.
Lisbon Bus Voyage oferece essa experiência de forma prática e divertida.
