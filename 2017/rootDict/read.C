#if !defined(__CINT__)

#include <TSystem.h>
#include <TFile.h>
#include <TClonesArray.h>

#include "Event.h"

#endif

using namespace MyProj;

void read() 
{

  Event *event;
  //TFile *f = TFile::Open("event_tca_m.root");
  TFile *f = TFile::Open("event_tca.root");

  TClonesArray *fEvents = (TClonesArray*)f->Get("Events");
  for (Int_t i = 0; i < fEvents->GetEntries(); i++) {
    event = (Event*)fEvents->At(i);
    if (i < 10) {
      printf("Event (tca) %s %s \n",event->GetName(),event->GetTitle());
      if (i == 0) event->Dump();
    }
  }

  f->Close();

}

