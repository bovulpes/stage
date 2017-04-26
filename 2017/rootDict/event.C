#if !defined(__CINT__)

#include <TSystem.h>
#include <TFile.h>
#include <TClonesArray.h>

#include "Event.h"

#endif

using namespace MyProj;

void event() 
{

  Event *event;
  Int_t nEvents = 10;
  TFile *f;

  f = new TFile("event_tca_m.root","recreate");

  TClonesArray *fEvents = new TClonesArray("MyProj::Event",10);
  TClonesArray &events = *fEvents;
  for (Int_t i = 0; i < nEvents; i++) {
    event = new(events[i]) Event(i, Form("N%d",i), Form("T%d",i));
  }

  fEvents->Write("Events",TObject::kSingleKey);

  f->Close();

}
