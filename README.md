# Longest Increasing Run

Gegeben sei eine beliebig lange, unsortierte Folge von positiven ganzen Zahlen (sequence, s) und die Anzahl n der Elemente dieser Folge, in C dargestellt durch folgende Vereinbarungen (mit Initialisierungen, die als Beispiel dienen):
Definieren Sie für die Ihre Funktionen sinnvolle Schnittstellen und testen Sie Ihre Bibliothek ausreichend.
#define MAX 100
/*0 1 2 3 4 5 6 7 8*/
int s[MAX] = { 9, 5, 2, 8, 7, 3, 1, 6, 4 }; int n = 9; /*number of elements in s*/

a) Der Longest Increasing Rung (LIR) ist die Länge der längsten zusammenhängenden Teilfolge (engl. run) von Elementen, deren Werte streng monoton steigend (engl. increasing) sind. Für das obige Beispiel 9, 5, 2, 8, 7, 3, 1, 6, 4 ergibt sich LIR = 2, die beiden längsten Läufe sind unterstrichen. – Wie Sie sicher sofort erkennen, kann man dieses Problem in O(n) lösen.

b) Die Berechnung der Longest Increasing Subsequence (LIS) ist eine viel spannendere Aufgabe. Sie besteht darin, die Länge der längsten nicht zusammenhängenden Teilfolge (engl. subsequence) monoton steigender Elemente zu ermitteln. Für das obige Beispiel ergibt sich LIS = 3, wobei es (rein zufällig) wieder zwei solcher längsten Teilfolgen gibt, nämlich 2, 3, 6 und 2, 3, 4. Mit dynamischer Programmierung lässt sich auch dieses Problem leicht lösen. Hier die zentrale Idee dafür: Wenn die LIS für alle Anfänge der Gesamtfolge, also z.B. für s[1..i-1] bekannt ist, so ergibt sich die LIS für die um 1 längere Anfangsfolge durch Hinzunahme des Elements s[i], indem die Länge der bisher längsten Teilfolge (also deren Maximum) um 1 erhöht wird, wenn diese mit einem Element s[j] < s[i] geendet hat. Diese Erkenntnis kann man in einem Feld l für alle Längen (engl. length) der Anfangsfolgen abbilden, dessen Elemente iterativ (für i = 1..n) wie folgt berechnet werden:

l[i] = Maxlj1, wobei s[j] < s[i] 1 ji

Um die Elemente der längsten Teilfolge(n) später auch rekonstruieren zu können, bietet es sich an, neben dem Feld l für auch ein Feld p für den Index des jeweiligen Vorgängers (engl. predecessor) mitzuführen. Folgende Tabelle zeigt das Ergebnis für obiges Beispiel:

index i 0 1 2 3 4 5 6 7 8 

sequences[i] 9 5 2 8 7 3 1 6 4

lengthsl[i] 1 1 1 2 2 2 1 3 3 =LIR 

predecessorsp[i] - - - 1 1 2 - 5 5

Entwickeln Sie ein C-Programm, das aus mindestens zwei Funktionen – jeweils eine für die Teilaufgaben a) und b) – mit identischer Schnittstelle
int LI?(int s[], int n);
besteht und aus einer main-Funktion, die im Wesentlichen einen Testreiber für die LI?-Funktionen darstellt. Teilen Sie Ihr C-Programm sinnvoll auf mehrere Übersetzungseinheiten (.c-Dateien) auf und geben Sie auch die dazugehörigen Header-Dateien (.h-Dateien) mit ab.
