Tema 1 nu este complet realizata, numai primele 3 cerinte fiind realizate.
Pentru implementarea solutiei, am ales 2 structuri de date de baza pentru a prelucra datele din fisierul de intrare. Pe deoparte, echipele sunt stocate intr-o lista simpla inlantuita, sub forma:

typedef struct team
{
    char *name;
    unsigned int player_number;
    struct team *next;
    player *array;
}team_node;

unde acel "array" reprezinta un vector cu toti jucatorii din aceea echipa. Strcutura pentru player este:

typedef struct player
{
    char *name, *surname;
    unsigned int points;
}player;

Avand in vedere ca lista de jucatori dintr-o echipa nu va fi modificata in sine, atunci este in regula sa alocam structura sub forma de vector.

Pentru cele 3 cerinte, abordarea consta in urmatoarele lucruri:
- Pentru prima cerinta, singurul lucru de facut este sa citim in ordine datele din fisierul "d.in" si sa afisam echipele in "r.out". Aici 
vom avea functiile pentru adaugarea la inceputul listei, alocarile de memorie pentru nodurile listei si vector, iar toate vor fi folosite 
in functia "Task1()" pentru rezolvarea cerintei.
- Pentru cea de a doua cerinta, trebuie sa gasesc o modalitate pentru a gasi nodurile cu media punctajului cea mai mica, apoi aceste noduri 
sa le scot din lista pana raman cu acea putere a lui 2, pe care o voi calcula in functia "Task2()" inainte de stergeri (aflarea acelui numar 
se poate face mai rapid folosindu-ne de operatori pe biti pentru a accelera calculele).
- Pentru cerinta 3, a trebuit sa implementez cele 2 structuri stiva si coada, pentru care am scris functiile de "Push()" si "Pop()", respecitv 
"EnQueue()" si "DeQueue()". Modul in care aceste structuri arata este in acest fel:
typedef struct stack
{
    team_node *address;
    struct stack *next;
}team_stack;
si
typedef struct queue_node
{
    struct queue_node *next;
    team_node *address;
}queue_node;
pentru un nod din coada plus
typedef struct queue
{
    queue_node *front, *rear;
}team_queue;
pentru o structura "capsula" pentru coada. Acestea fiind adresate, in "Task3()" unde am implementat rezolvarea cerinte propriu-zis, am luat 
si inceput a trece invingatorii si pierzatorii din coada de echipe pentru a juca meciuri, apoi cand coada a devenit goala, am adus invingatorii 
din stiva de invingatori si i-am pus inapoi in coada de meciuri, asta pana cand am mai ramas cu o singura echipa. Pentru opearatiile in care mutam 
echipe din coada in stiva si vice-versa, am afisat dupa modelul din fisier datele relevante. La final, toata memoria am eliberat-o. Aceasta se 
poate verifica la final folosind Valgrind.

Consider ca Tema 1 este utila atat pentru a invata structurile de date complexe precum liste inlantuite si toate structurile derivate din ele, 
cat si modul de structurare a codului si fragmentarea codului pentru a lucra mai usor cu acesta. Din acest punct de motive, am decis ca fiecare 
cerinta sa aiba fisiere sursa diferite pentru a delimita utilitatea functiilor. Am avut si cazul in care a trebui sa folosesc functii de la 
subpunctele trecute, cum ar fi "DeleteTeamNode()" in cerinta 3, desi functia a fost mai intai folosita in cerinta 2, doar ca refolosirea de cod 
nu reprezinta o problema atata timp cat scrierea acestor functii a fost generalizata, ruland indiferent de context.

Implementarea totusi este pe departe perfecta. Nu tot codul este implementat in mod generic (cum ar fi stiva si coada din cerinta 3, sau functia 
"AddAtBeginningTeam()", unde am facut si citire de date, astfel incat acum functia nu poate fi refolosita in a adauga elemente cu date deja 
citite in alte liste, cum ar fi trebuit in cerinta 3 sa fi adaugat in alta lista ultimele 8 echipe finaliste). De asemenea, este posibil ca 
algoritmul sa nu fie eficient din punct de vedere al timpului (programul calculeaza de fiecare data cand are nevoie media echipei, ceea ce 
pentru un numar mare de echipe dureaza foarte mult sa iau si sa reiau acel calcul. Ar fi fost mai bine sa fi retinut mediile intr-un vector/lista 
separata, unde complexitatea de spatiu ridicata ar fi fost mult mai convenienta fata de timpul bonus pentru care programul face calcule aditionale. Cred ca un alt obiectiv esuat a fost comentarea corecta/utila a codului, intrucat am scris comentarii in principiu numai legat de utilizarea functiilor in sine, per ansamblu, dar nu si a secventelor de cod propriu-zise din cadrul fisierelor sursa.

Asa cum am precizat anterior, in program imi lipsesc cerintele 4 si 5, si din cerinta 3, desi testele afiseaza corect, nu am pregatit lista 
de echipe invingatoare, acelea 8. Probabil cel mai greu aspect al acestei teme a fost organizarea functiilor si a structurilor de date asa 
incat codul sa fie inteles usor, atat de mine cat si de cine corecteaza tema. Pe langa denumirile descritive ale functiilor, am si adaugat 
comentarii despre niste informatii specifice de stiu legate de functie pentru a fi mai usor de inteles de ce am abordat implementarea in acel fel. 

2 lucruri interesante pe care am reusit sa le imbunatatesc au fost lucrurul cu mai multe fisiere intr-un proiect mai mare (inclusiv sa 
folosesc makefile-uri) si sa depanez cod folosind programul Valgrind, cu care a fost mult mai usor sa vad erorile de cod si locurile unde 
memoria nu a fost eliberata cum trebuie. Cred ca prin aceasta tema am apucat sa imi imbunatatesc stilul de programare.