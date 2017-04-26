Création d'objets, écriture/lecture dans un fichier, dictionnaire
-----------------------------------------------------------------

* Initialisation de ROOT

```bash
alienv enter -w /users_local1/vulpescu/Software/alice/sw-root6 AliRoot/latest-ali-master-root6-root6
```

* Compiler le code (avec création de dictionnaire)

```bash
make
```

le code source est: Event.cxx + Event.h + EventLinkDef.h (le dernier est essentiel dans la création du dictionnaire)

* exécuter et produire le fichier sortie event_tca.root

```bash
./Event
```

* Lire le fichier event_tca.root (tca = TClonesArray)

```bash
root.exe -b -q read.C+
```

"+" signifie exécution en mode compilé

* Lire le fichier en mode interprété

root.exe
.L read.C
read()

* exécuter une macro (macro-instruction) dans ROOT en mode interprété

```bash
root.exe -b -q event.C+
```
pour produire un fichier similaire event_tca_m.root

