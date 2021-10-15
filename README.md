#CIUREA Robert-Mihai - 313CB

Tema 1 –Structuri de date (seria CB)
Tabele hash
                                                        
Pentru scrierea programului au fost necesare o serie de implementari care au
stat la baza intregului program, precum: functii de operare pe liste generice
dublu-inlantuite, precum si liste de operare pe tabele hash. 

Pentru a putea lucrea cu liste a fost necesara definirea unei structuri de
tip lista in care s-au definit campul destinat retinerii informatiei precum si
campurile de pointeri meniti sa permita avansarea sau devansarea prin lista,
conform necesitatilor. Functiile necesare lucrului cu liste au fost cea de
initializare a unei liste, respectiv functia de adaugare in lista. Restul 
functiilor necesare implementarii programului s-au bazat strict pe operatiile
pe tabele hash.

Pentru a putea lucra cu tabele hash, a fost necesara implementarea unei structuri
de tip tabela hash in care se stocau numarul de elemente din vectorul de liste,
functia hash necesara identificarii indexului unde trebuiau puse viitoarele
elemente ale tabele hash, iar pentru un lucru mai usor cu listele tabelei hash
am ales declararea unui vector de lungimi de dimeniunea vectorului de liste
astfel incat fiecare element din vectorul de lungimi reprezenta lungimea
fiecarei liste din vectorul de liste al tabelei hash. Ca functii orientate
generic pe orice tip de tabela hash, s-a lucrat cu 3 functii principale: functia
de returnare a codului hash, functia de creare a unei tabele goale, respectiv
functia de eliberare a intregii memorii utilizate de o tabela hash.

Functia de returnare a codului hash primeste ca parametru de intrare si lungimea
tabelei hash si returneaza restul impartirii sumei valorilor ascii ale
caracterelor string-ului la dimensiunea tabelei pentru a returna un numar mai mic
decat dimensiunea tabelei, astfel incat sa fie posibila o indexare eficienta a
fiecarui element in tabela hash.

Functia de creare a tabelei hash initializeaza un tip de data tabel si aloca
memoire pentru toate elementele acestuia, pentru a permite finctionalitatea
functiilor aferente finalizarii programului, pentru ca functia de stergere sa
asigure intreaga eliberare a memoriei alocate in heap.

Pentru realizarea propriu-zisa a programului a fost nevoie de cate o functie
atribuita fiecarei comenzi citite din fisier astfel incat sa se poata efectua
operatiile pe tabela hash (put, get, find, remove, print, print_bucket).

Functia de put, folosinde-se de functia hash si de string ce se doreste a fi
introdus in tabela hash, acceseaza lista aferenta codului hash returnat de
functia hash si verifica daca elementul respectiv din vector are sau un cap de
lista initializat. Daca are atunci doar insereaza mai departe in lista un nou
nod cu informatia corespunzatoare. Insa, daca head-ul nu este initializat, atunci
se apeleaza functia de initializare de lista si se introduce informatia in nodul
creat. In cadrul functiei se verifica daca key-ul a mai fost sau nu introdus,
iar in cazul in care a mai fost deja odata introdus, nu se mai introduce din nou
si se elibereaza memoria ce fusese utilizata pentru memorarea temporara a
elementelor caracteristice unui site.

Functia get, folosindu-se de functia hash, acceseaza lista aferenta codului
hash returnat pe baza key-ului, astfel incat sa aiba loc parcurgerea listei pana
la gasirea key-ului in lista sau pana la parcurgerea intregii liste. Daca key-ul
se gaseste, functia se opreste si returneaza valoarea stocata pentru acel key, in
caz contrar se returneaza NULL.

Functia remove are acelas sistem de cautare precum functia get, insa daca gaseste
key-ul, atunci are loc procesul de schimbare de legaturi astfel incat nodul ce
contine key-ul sa nu mai fie legat de alte noduri, pentru ca ulterior sa-i fie
eliberata intreaga memorie stocata.

Functia find prezinta acelas sistem de cautare precum functiile get si remove,
insa daca gaseste key-ul returneaza TRUE, in caz contrar False.

Functiile print si print_bucket au functionalitati asemanatoare, ambele asigurand
afisarea elementelor din tabela hash, diferenta aparand la faptul ca functia print
afiseaza toate listele sortate alfabetic, in timp ce print_bucket asigura afisarea
doar a unei singure liste ce este specificata ca parametru a functiei. Pentru
efectuarea sortarii elementelor inainte de afisare a fost implementata o functie
de sortare ce are la baza un bubble sort prin care compara toate elementele intre
ele dintr-o lista si in cazul in care sunt intalnite 2 key-uri care nu sunt in
ordine alfabetica, atunci asigura interschimbarea informatiilor din noduri pentru
ca in urma apelarii functiei toate listele din tabela hash sa fie ordonate alfabetic.
Trebuie sa se tina cont ca daca are loc orice tip de afisare odata si dupa se
introduc alte elemente in liste, functiile de printare apeleaza la inceput de
fiecare data functia de sortare pentru a se asigura ca mereu afisarea listelor
din tabela hash sa fie ordonate alfabetic.