#include <TNamed.h>

class TH1F;

class Event : public TNamed {

 public:
   Event(Char_t *name, Char_t *title);
   Event();
   virtual ~Event();
 
 private:
   Int_t     fM1; //
   Float_t   fM2; //
   Int_t     fN;  //
   TH1F     *fH1; //->
   Double_t *fD;  //[fN]

   ClassDef(Event,1)

};

