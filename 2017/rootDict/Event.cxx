#include <TH1F.h>
#include <TClass.h>
#include <TFile.h>
#include <TClonesArray.h>

#include "Event.h"

Event::Event():
TNamed("",""),
fM1(0),
fM2(0.),
fN(5),
fH1(),
fD()
{
  // Default constructor
}

Event::Event(Char_t *name, Char_t *title):
TNamed(name,title),
fM1(1),
fM2(1.),
fN(5)
{

  //printf("Construct object %s : %s \n",name,title);
  fH1 = new TH1F(Form("%s_H1",name),Form("%s_H1",title),10,0,10);
  fD = new Double_t[fN];

}

Event::~Event() {

  delete fH1;
  delete [] fD;

}

ClassImp(Event)

int main(int argc, char * argv[]) {

  Event *event;

  Int_t nEvents = 10;

  TFile *f;

  // (1) write objects

  f = new TFile("event.root","recreate");

  for (Int_t i = 0; i < nEvents; i++) {
    event = new Event(Form("N%d",i),Form("T%d",i));
    event->Write(Form("Event%d",i));
  }

  f->Close();

  // (2) write TClonesArray of objects

  TClonesArray *fEvents = new TClonesArray("Event",10);

  f = new TFile("event_tca.root","recreate");

  TClonesArray &events = *fEvents;
  for (Int_t i = 0; i < nEvents; i++) {
    Event *event = new(events[i]) Event(Form("N%d",i),Form("T%d",i));
  }

  // this gives the same file size as (1)
  //fEvents->Write();

  fEvents->Write("Events",TObject::kSingleKey);

  f->Close();

  return 0;

}
