#include "LibPig.h"

	void nivelBasico(){
		
			
			style(BRIGHT);
			
			srand(time(NULL)); // para que os valores aleatorios nao se repitam a cada execucao
			
			tJogador player; 
			tJogador pontJogador, pontMaquina;
			pontJogador.score = 0, pontMaquina.score = 0; // variaveis do tipo struct
			int dadoJogador = 0, dadoMaquina = 0;
			int rodada = 0, op, ip, finish = 0; // variaveis auxiliares
			
			
			printf(" %c------------------------------------------------------------%c\n",201,187);
            printf(" | ");printf("\t\t\t     GAME PIG");printf("\t\t\t      |\n");
            printf(" %c------------------------------------------------------------%c\n",200,188);
    	    printf("\n\n");
			puts("Sorteio para ver quem comeca"); // ALGORITMO para ver qm comeca jogando..
			puts("Deseja ser IMPAR ou PAR? (1 - IMPAR / 2 - PAR)");
			scanf("%d", &ip);
			fflush(stdin);
														
			puts("SORTEANDO... ");
			for(int cont = 3; cont>=1; cont--){
				printf(" %d,", cont);
				Sleep(800);
			}

			int qmComeca = (rand()%1) +1;
			if(qmComeca == 1){
				printf("\n  IMPAR COMECA!\n");
			}else{
				printf("\n  PAR COMECA!\n");
			} // FIM do ALGORITMO
		
				
			while(finish != 1){
			
			for(rodada = 0; rodada<10; rodada++){
				
				system("pause");
				system("cls");
				printf("   |-----------------------------------------|\n");
				printf("   |--------------- RODADA %d ----------------|\n", rodada+1);
				printf("   |-----------------------------------------|\n");
				if(qmComeca == ip){  //  Se o jogador vencer o sorteio, ele comeca
					
					system("color 1F");
					style(BRIGHT);
					
					printf("\nEh a vez do JOGADOR de lancar o dado, (nome do jogador atual)"); // É necessário criar o vetor para puxar o nome do jogador atual(ponteiro)
					puts("");
					do{
					
					puts("LANCANDO o DADO...");
					for(int cont=3; cont>=1; cont--){
						printf(" %d,", cont);
						Sleep(300);				
					}
					printf("\n");
					system("pause");
					printf("\n");
					
					dadoJogador = (rand()%5) + 1;
					printf("\n\tRESULTADO [ %d ]" , dadoJogador);
				
				
						if(dadoJogador != 1){
							
							pontJogador.score += dadoJogador;
							printf("\n\tSUA PONTUACAO ATUAL [ %d ]", pontJogador.score);
							//se o jogador atingir 100 pontos, ele vencera
							if(pontJogador.score >= 100){
								printf("\nVOCE VENCEU");
								// o usuario lanca os dados enquanto diferente de 1, ou seja, 1 eh o criterio de parada
								dadoJogador = 1;
								// criterio de parada do while principal
								finish = 1;
								break;
							}
								printf("\n\n");
					      		printf("   %c-----------%c----------%c------------%c \n",201,200,188,187);
    						    printf("   | <1>  LANCAR O DADO NOVAMENTE      |\n");
     	 						printf("   |-----------------------------------|\n");
     	 						printf("   | <2>  PASSAR A VEZ                 |\n");         
     	 						printf("   %c-----------------------------------%c",200,188);
								printf("\n\t * ESCOLHA UMA OPCAO *");
							
							puts("");
							scanf("%d", &op);
							fflush(stdin);
				
							switch(op){
								case 1: 
								dadoJogador = 1;
								break;
							
								case 2:
								dadoJogador = 1; // falta o codigo para passar a vez
								qmComeca = 3;
								break;
								
							default:
							puts("Opcao Invalida!");
					} 
					
				}else{
					pontJogador.score = 0;  // quando o resultado do dado é igual a 1, também eh necessário passar a vez
					qmComeca = 3;
					puts("\nOPS... Sua pontuacao foi zerada! :-(");
				
					
				} // chave do else(dados = 1)
				
			}while(dadoJogador != 1);
			
	
	
				}else{
					style(BRIGHT);
					system("color 4F");
					//foreground(GREEN);
					
					
					printf("\nEh a vez da MAQUINA jogar o dado..."); 
					puts("");
			
					do{
						
						puts("LANCANDO o DADO...");
						for(int cont = 3; cont>=1; cont--){
							printf(" %d,", cont);
							Sleep(300);
							
						}
						printf("\n");
						system("pause");
						printf("\n");
						dadoMaquina = (rand()%5) + 1;
						printf("\n\tRESULTADO [ %d ]", dadoMaquina);
				
				
							if(dadoMaquina != 1){
								pontMaquina.score += dadoMaquina;
								printf("\n\tPONTUACAO DO COMPUTADOR [ %d ]" , pontMaquina.score);
								
								printf("\n\n");
      							printf("   %c-----------%c----------%c------------%c \n",201,200,188,187);
      	 						printf("   | <1>  LANCAR O DADO NOVAMENTE      |\n");
     	 						printf("   |-----------------------------------|\n");
     	 						printf("   | <2>  PASSAR A VEZ                 |\n");      
     	 						printf("   %c-----------------------------------%c",200,188);
     	 						
								printf("\n\t * ESCOLHA UMA OPCAO *");
								
								puts("");
								scanf("%d", &op);
								fflush(stdin);
				
								switch(op){
									case 1: 
									dadoMaquina = 1;
									break;
							
									case 2:
									dadoMaquina = 1; // falta o codigo para passar a vez
									qmComeca = ip;
									break;
									
								
									default:
									puts("Opcao Invalida!");
								}
					
							}else{
								pontMaquina.score = 0; // quando o resultado do dado é igual a 1, também precisa passar a vez
								qmComeca = ip;
								puts("\nOPS.. Sua pontuacao foi zerada! :-(");				
							}// chave do else(dadoMaquina == 1)
							
					}while(dadoMaquina != 1);
					
				} // chave do else
			} // for rodada
			finish = 1;
			system("pause");
			puts("");
			//apos 100 rodadas, verifica qm fez a maior pontuacao
			if(pontJogador.score > pontMaquina.score){
				style(BRIGHT);
				system("color 1F");
				system("cls");
				printf("\n\n\n\tPARABENS! VOCE VENCEU! :)");
				printf("\n");
				system("pause");
				telaMenu();
				puts("");
			
			}else{
				style(BRIGHT);
				system("color 4F");
				system("cls");
				printf("\n\n\n\t VOCE PERDEU! :(");
				puts("");
				system("pause");
				telaMenu();
				puts("");
			}
		} // chave do while para encerrar
	} // chave da funcao
	
	
	void nivelDificil(){
			style(BRIGHT);
			srand(time(NULL)); // para que os valores aleatorios nao se repitam a cada execucao
			tJogador player; 
			tJogador pontJogador, pontMaquina;
			pontJogador.score2 = 0, pontMaquina.score2 = 0; // variaveis do tipo struct
			int dadoJogador1 = 0, dadoJogador2 = 0, dadoMaquina1 = 0, dadoMaquina2 = 0;
			int rodada = 0, op, ip, finish = 0; // variaveis auxiliares
			
			
			printf(" %c------------------------------------------------------------%c\n",201,187);
      printf(" | ");printf("\t\t\t     GAME PIG");printf("\t\t\t      |\n");
      printf(" %c------------------------------------------------------------%c\n",200,188);
    	printf("\n\n");
			puts("Sorteio para ver quem comeca"); // ALGORITMO para ver qm comeca jogando..
			puts("Deseja ser IMPAR ou PAR? (1 - IMPAR / 2 - PAR)");
			scanf("%d", &ip);
			fflush(stdin);
														
			puts("SORTEANDO... ");
			for(int cont = 3; cont>=1; cont--){
				printf(" %d,", cont);
				Sleep(800);
			}

			int qmComeca = (rand()%1) +1;
			if(qmComeca == 1){
				printf("\n  IMPAR COMECA!\n");
			}else{
				printf("\n  PAR COMECA!\n");
			} // FIM do ALGORITMO
		
				
			while(finish != 1){
			
			for(rodada = 0; rodada<10; rodada++){
				
				system("pause");
				system("cls");
				printf("   |-----------------------------------------|\n");
				printf("   |--------------- RODADA %d ----------------|\n", rodada+1);
				printf("   |-----------------------------------------|\n");
				if(qmComeca == ip){  //  Se o jogador vencer o sorteio, ele comeca
					
					system("color 1F");
					style(BRIGHT);
					
					printf("\nEh a vez do JOGADOR de lancar os dados, (nome do jogador atual)"); // É necessário criar o vetor para puxar o nome do jogador atual(ponteiro)
					puts("");
					do{
					
					puts("LANCANDO os DADOS...");
					for(int cont=3; cont>=1; cont--){
						printf(" %d,", cont);
						Sleep(300);				
					}
					printf("\n");
					system("pause");
					printf("\n");
					
					dadoJogador1 = (rand()%5) + 1;
					dadoJogador2 = (rand()%5) + 1;
					printf("\n\tRESULTADO DO 1o DADO [ %d ]" , dadoJogador1);
					printf("\n\tRESULTADO DO 2o DADO [ %d ]" , dadoJogador2);
				
				
						if(dadoJogador1 != 1 && dadoJogador2 != 1){
							
							pontJogador.score2 += dadoJogador1 + dadoJogador2;
							printf("\n\tSUA PONTUACAO ATUAL [ %d ]", pontJogador.score2);
							//se o jogador atingir 100 pontos, ele vencera
							if(pontJogador.score2 >= 100){
								printf("\nVOCE VENCEU");
								// o usuario lanca os dados enquanto diferente de 1, ou seja, 1 eh o criterio de parada
								dadoJogador1 = 1;
								dadoJogador2 = 1;
								// criterio de parada do while principal
								finish = 1;
								break;
							}
								printf("\n\n");
					      		printf("   %c-----------%c----------%c------------%c \n",201,200,188,187);
    						    printf("   | <1>  LANCAR OS DADOS NOVAMENTE    |\n");
     	 						printf("   |-----------------------------------|\n");
     	 						printf("   | <2>  PASSAR A VEZ                 |\n");         
     	 						printf("   %c-----------------------------------%c",200,188);
								printf("\n\t * ESCOLHA UMA OPCAO *");
							
							puts("");
							scanf("%d", &op);
							fflush(stdin);
				
							switch(op){
								case 1: 
								dadoJogador1 = 1;
								dadoJogador2 = 1;
								break;
							
								case 2:
								dadoJogador1 = 1; // falta o codigo para passar a vez
								dadoJogador2 = 1;
								qmComeca = 3;
								break;
								
							default:
							puts("Opcao Invalida!");
					} 
					
				}else{
					pontJogador.score2 = 0;  // quando o resultado do dado é igual a 1, também eh necessário passar a vez
					qmComeca = 3;
					puts("\nOPS... Sua pontuacao foi zerada! :-(");
					puts("");
					
				} // chave do else(dados = 1)
				
			}while(dadoJogador1 != 1 && dadoJogador2 != 1);
			
	
	
				}else{
					style(BRIGHT);
					system("color 4F");
					//foreground(GREEN);
					
					
					printf("\nEh a vez da MAQUINA jogar os dados..."); 
					puts("");
			
					do{
						
						puts("LANCANDO os DADOS...");
						for(int cont = 3; cont>=1; cont--){
							printf(" %d,", cont);
							Sleep(300);
							
						}
						printf("\n");
						system("pause");
						printf("\n");
						dadoMaquina1 = (rand()%5) + 1;
						dadoMaquina2 = (rand()%5) + 1;
						printf("\n\tRESULTADO DO 1o DADO [ %d ]", dadoMaquina1);
						printf("\n\tRESULTADO DO 2o DADO [ %d ]", dadoMaquina2);
				
				
							if(dadoMaquina1 != 1 && dadoMaquina2 != 1){
								pontMaquina.score2 += dadoMaquina1 + dadoMaquina2;
								printf("\n\tPONTUACAO DO COMPUTADOR [ %d ]" , pontMaquina.score2);
								
								printf("\n\n");
      							printf("   %c-----------%c----------%c------------%c \n",201,200,188,187);
      	 						printf("   | <1>  LANCAR DADOS NOVAMENTE       |\n");
     	 						printf("   |-----------------------------------|\n");
     	 						printf("   | <2>  PASSAR A VEZ                 |\n");      
     	 						printf("   %c-----------------------------------%c",200,188);
     	 						
								printf("\n\t * ESCOLHA UMA OPCAO *");
								
								puts("");
								scanf("%d", &op);
								fflush(stdin);
				
								switch(op){
									case 1: 
									dadoMaquina1 = 1;
									dadoMaquina2 = 1;
									break;
							
									case 2:
									dadoMaquina1 = 1; // falta o codigo para passar a vez
									dadoMaquina2 = 1;
									qmComeca = ip;
									break;
									
								
									default:
									puts("Opcao Invalida!");
								}
					
							}else{
								pontMaquina.score2 = 0; // quando o resultado do dado é igual a 1, também precisa passar a vez
								qmComeca = ip;
								puts("\nOPS.. Sua pontuacao foi zerada! :-(");	
								
											
							}// chave do else(dadoMaquina == 1)
							
					}while(dadoMaquina1 != 1 && dadoMaquina2 != 1);
					
				} // chave do else
			} // for rodada
			finish = 1;
			system("pause");
			puts("");
			//apos 100 rodadas, verifica qm fez a maior pontuacao
			if(pontJogador.score2 > pontMaquina.score2){
				style(BRIGHT);
				system("color 1F");
				system("cls");
				printf("\n\n\n\tPARABENS! VOCE VENCEU! :)");
				printf("\n");
				system("pause");
				telaMenu();
				puts("");
			}else{
				style(BRIGHT);
				system("color 4F");
				system("cls");
				printf("\n\n\n\tA VOCE PERDEU! :(");
				printf("\n");
				system("pause");
				telaMenu();
				puts("");
			}
		} // chave do while para encerrar
	} // chave da funcao
	
	void telaGame(){
			style(BRIGHT);
			system("cls");
			
			
			tJogador player; // provavelmente vai ser um vetor e registrar os nomes no arquivo e verificar se já existe
			tJogador hardness;
			int i;
			printf(" %c------------------------------------------------------------%c\n",201,187);
      printf(" | ");printf("\t\t\t     GAME PIG");printf("\t\t\t      |\n");
      printf(" %c------------------------------------------------------------%c\n",200,188);
			puts("");
			
			
			printf("\t\tINFORME O SEU NICKNAME > ");
			gets(player.nickname);
			puts("");
			
				
			printf("\t BEM-VINDO, %s ! ^_^", player.nickname);
			puts("");
			puts("");
			
			do{	
			printf("   %c-----------%c----------%c------------%c \n",201,200,188,187);
      printf("   | <0>  Nivel Basico                 |\n");
      printf("   |-----------------------------------|\n");
      printf("   | <1>  Nivel Dificil                |\n");      
      printf("   %c-----------------------------------%c",200,188);
      printf("\n\n");	
			puts("\t* ESCOLA A DIFICULDADE *");
			puts("");
			scanf("    %d", &hardness.dificuldade);
			fflush(stdin);
			
			switch(hardness.dificuldade){
				case basico:
					//inicia o jogo com o nivel basico
					system("cls");
					nivelBasico();
					
					break;
				
				case dificil:
					//inicia o jogo com o nivel dificil
					system("cls");
					nivelDificil();
					break;
					
				default:
					puts("Opcao invalida!");
					system("pause");
					printf("\n\n\n");
					system("cls");
					puts("");
				
			}
				
		}while(hardness.dificuldade != 0 || hardness.dificuldade != 1);
			
			
			
			system("pause");
		}
		
	void telaMenu(){
			style(BRIGHT);
			system("cls");
			fflush(stdin);
			tOpcao op;
			
			puts("");
			
			
			do{
				style(BRIGHT);
			printf(" %c------------------------------------------------------------%c\n",201,187);
      printf(" | ");printf("\t\t\t     MENU OPCOES");printf("\t\t      |\n");
      printf(" %c------------------------------------------------------------%c\n",200,188);	
      		puts("");
      		printf("   %c-----------%c----------%c------------%c \n",201,200,188,187);
      	 printf("   | <1>  INICIAR NOVO JOGO            |\n");
     	 printf("   |-----------------------------------|\n");
     	 printf("   | <2>  VISUALIZAR RANKING           |\n");      
     	 printf("   |-----------------------------------|\n");
     	 printf("   | <3>  SAIR DO JOGO                 |\n");      
     	
     	 printf("   %c-----------------------------------%c",200,188);
      printf("\n\n");
			puts("\t* ESCOLA UMA OPCAO *");
			scanf("%d", &op.select);
			fflush(stdin);
			
			if(op.select == 1){
				//chamar funcao para iniciar o game
				telaGame();
			}
			if(op.select == 2){
				//abrir o arquivo com o ranking dos jogadores
			}
			if(op.select == 3){
				//funcao para encerrar o programa
				printf("GoodBye o/");
				exit (0);
			}
			system("cls");
		}while(op.select != 3);
			system("pause");
		}
		
	void telaLogin(){
			tLogin log;
			
			printf(" %c------------------------------------------------------------%c\n",201,187);
      printf(" | ");printf("\t\t\t     LOGIN");printf("\t\t\t      |\n");
      printf(" %c------------------------------------------------------------%c\n",200,188);
    	printf("\n\n");
      printf("|      USUARIO > ");      
     				gets(log.user);
      printf("|      SENHA   > ");      
      				 gets(log.password);
			       
	
				//se usuario e senha corretos, é aberto a tela menu
				if(strcmp(log.user, "admin") == 0 && strcmp(log.password, "admin") == 0){
				//menu opcoes
				telaMenu();
				}else{
					
					puts(" ");
					
					//While para digitar usuário e senha até ser o correto
					while((strcmp(log.user, "admin") != 0) || (strcmp(log.password, "admin") != 0)){
						
						puts(" ");
						puts("USUARIO E/OU SENHA ESTA/ESTAO INCORRETO(S)!");
						
							printf("\n\n");
                     printf("|      USUARIO > ");      
     				   gets(log.user);
                     printf("|      SENHA   > ");      
      				   gets(log.password);
      				 
					}
					
					//se usuario e senha corretos, é aberto a tela menu
				    if(strcmp(log.user, "admin") == 0 && strcmp(log.password, "admin") == 0){
				     //menu opcoes
				      telaMenu();
				}
				}
		}	

