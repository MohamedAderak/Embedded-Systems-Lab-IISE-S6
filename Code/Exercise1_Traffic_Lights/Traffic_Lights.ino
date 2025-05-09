const int R1 = 2, J1 = 3, V1 = 4;
const int R2 = 5, J2 = 6, V2 = 7;

int tempsVert = 5000;
int tempsJaune = 2000;
int tempsRouge = 5000;

void setup() {
  pinMode(R1, OUTPUT);
  pinMode(J1, OUTPUT);
  pinMode(V1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(J2, OUTPUT);
  pinMode(V2, OUTPUT);

  digitalWrite(R1, LOW);
  digitalWrite(J1, LOW);
  digitalWrite(V1, LOW);
  digitalWrite(R2, LOW);
  digitalWrite(J2, LOW);
  digitalWrite(V2, LOW);
}

void loop() {
  //---------- Phase 1 : Groupe 1 Vert | Groupe 2 Rouge ----------
  digitalWrite(V1, HIGH);
  digitalWrite(R2, HIGH);
  delay(tempsVert);

  // Transition Groupe 1 : Vert → Jaune
  digitalWrite(V1, LOW);
  digitalWrite(J1, HIGH);
  delay(tempsJaune);

  //---------- Phase 2 : Groupe 1 Rouge | Groupe 2 Vert ----------
  digitalWrite(J1, LOW);
  digitalWrite(R1, HIGH);
  digitalWrite(R2, LOW);
  digitalWrite(V2, HIGH);
  delay(tempsVert);

  // Transition Groupe 2 : Vert → Jaune
  digitalWrite(V2, LOW);
  digitalWrite(J2, HIGH);
  delay(tempsJaune);

  // Réinitialiser pour le cycle suivant
  digitalWrite(J2, LOW);
  digitalWrite(R1, LOW);
}
