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

👨‍💻 Instruções para Programadores
1. Clonar o repositório:
bash
Copy
git clone https://github.com/rodrigorocha/LisbonBusVoyage.git
2. Abrir o projeto
Abrir o projeto no Code::Blocks ou outro IDE compatível com C.
3. Compilar o programa:
bash
Copy
gcc main.c funcoes.c -o LisbonBusVoyage
4. Executar:
bash
Copy
./LisbonBusVoyage
5. Explorar
Navega pelo menu e testa todas as funcionalidades disponíveis.
🖼️ Exemplo de Execução
yaml
Copy
Bem-vindo ao Lisbon Bus Voyage!
Escolha o seu destino:
1 - Lisboa -> Porto
2 - Lisboa -> Coimbra
3 - Lisboa -> Faro
Escolha o destino: 2

Número de bilhetes: 3
Preço total: 30€

Confirma a compra? (S/N): S
Compra realizada com sucesso! Obrigado por viajar connosco.
📈 Melhorias Futuras
✅ Adicionar suporte a mais destinos e horários
✅ Guardar histórico de compras dos utilizadores
✅ Interface gráfica simples com GTK ou ncurses
✅ Implementar persistência de dados mais avançada com ficheiros binários

## 📌 Considerações Finais
Lisbon Bus Voyage é um projeto educativo que combina lógica de programação, modularidade e gestão de dados.
Permite ao utilizador interagir com um sistema realista de bilheteira, ao mesmo tempo que consolida conhecimentos fundamentais em linguagem C.
Aprender programação é mais eficaz quando aplicamos os conceitos em projetos reais.
Lisbon Bus Voyage oferece essa experiência de forma prática e divertida.
