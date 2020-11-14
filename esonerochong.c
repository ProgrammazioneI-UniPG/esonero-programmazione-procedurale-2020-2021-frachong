// includo le librerie
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//inizializzazione della funzione main
int main(){
  //dichiarazione variabili
  time_t t;
  int opzione;
  char plaintext[130];
  char chiave[130];
  int lunghezza;
  int lunghezza_chiave;
  int ch;
  char testo_cifrato[130];
  char testo_decifrato[130];
  int i;
  i=0;
  int s;
  s=0;

  //inserimento della stringa da parte dell'utente
  printf("Inserisci una stringa di non più di 128 caratteri:");
  fgets(plaintext,130,stdin);
  //funzione che permette di tagliare tutti i caratteri in eccesso
  while((ch= getchar() !='\n' && ch !=EOF));

  //mostro la stringa e la sua lunghezza
  printf("La tua stringa è: %s\n", plaintext);
  lunghezza=strlen(plaintext)-1;
  printf("La lunghezza della tua stringa è:%d\n\n", lunghezza);

  //scelta dell'opzione da parte dell'utente
  printf("Ora che hai inserito il testo puoi scegliere tra diverse opzioni:\n-Se digiti 1 dovrai inserire la chiave da tastiera\n-Se digiti 2 ti verrà generata una chiave di cifratura\n-Se non digiti nessuna delle due opzioni il programma terminerà \n");
  scanf ("%d", &opzione);
    int dh;
    while((dh= getchar() !='\n' && dh !=EOF));

  //utente sceglie opzione 1
    if(opzione==1){
        do{
        printf("Inserisci una chiave di non più di 128 caratteri: ");
        fgets(chiave,130,stdin);
        while ((ch= getchar() !='\n' && ch !=EOF));
        lunghezza_chiave = strlen(chiave)-1;
        printf("la lunghezza della chiave è: %d\n", lunghezza_chiave);
        }
          //finché l'utente non inserirà una chiave maggiore o uguale al testo inserito precedentemente, dovrà inserire un'altra chiave
          while (lunghezza_chiave<lunghezza);
          printf("La lunghezza della chiave è corretta poichè è di lunghezza maggiore o uguale al testo\n");

            if(lunghezza<=lunghezza_chiave){
                printf ("il testo cifrato è: ");
                //cifro il testo testo tramite la funzione XOR
                while(i<lunghezza){
                  testo_cifrato[i]=plaintext[i]^chiave[i];
                  printf("%X", testo_cifrato[i]);
                  i++;
                }
                printf("\n");

                i=0;
                //decifro il testo tramite la funzione XOR
                while(i<lunghezza){
                  testo_decifrato[i]=testo_cifrato[i]^chiave[i];
                  i++;
                }
                printf("Il testo decifrato è: %s\n", testo_decifrato);

            }

        }

      //utente sceglie opzione 2
      else if(opzione==2){
          //generazione della chiave random
          srand((unsigned) time(&t));
          unsigned char chiave_random[s];
          printf("Ecco la chiave che ti è stata generata:");
          while(s<lunghezza) {
          chiave_random[s]=32+(rand()%128);
          printf("%X", chiave_random[s]);
          s++;
          }
          printf("\n");

          s=0;
          printf("il testo cifrato è:");
          //cifro il testo tramite la funzione XOR
          while(s<lunghezza) {
          testo_cifrato[s]=plaintext[s]^chiave_random[s];
          printf("%X", testo_cifrato[s]);
          s++;

          }
          printf("\n");
          s=0;
          //decifro il testo tramite la funzione XOR
          while(s<lunghezza){
          testo_decifrato[s]=testo_cifrato[s]^chiave_random[s];
            s++;
          }
          printf("Il testo decifrato è: %s\n", testo_decifrato);
        }

        //utente sceglie diversamente rispetto alle due opzioni, perciò il programma terminerà
        else{
          printf("Non è stata scelta nessuna delle due opzioni perciò il programma terminerà qui ");
        }



        }
