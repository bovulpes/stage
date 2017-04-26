#include <TH1F.h>
#include <TClass.h>
#include <TFile.h>
#include <TClonesArray.h>

#include "Event.h"

using namespace MyProj;

ClassImp(MyProj::Event)

//____________________________________________________________________________
Event::Event():
TNamed("",""),
fM1(0),
fM2(0.),
fN(5),
fH1(nullptr),
fD(nullptr),
fDv()
{
  // Default constructor
}

//____________________________________________________________________________
Event::Event(Int_t iev):
TNamed(Form("N%d",iev), Form("T%d",iev)),
fM1(1),
fM2(1.),
fN(5),
fH1(nullptr), // C++11
fD(new Double_t[fN]), // C++11
fDv()
{

  //printf("Construct object %d %s : %s \n",iev,name,title);
  fH1 = new TH1F(Form("N%d_H1",iev),Form("T%d_H1",iev),10,0,10);
  fH1->SetBinContent(iev,1.);
  fDv = { 1000.+iev, 2000.+iev, 3000.+iev, 4000.+iev, 5000.+iev }; // C++11

}

//____________________________________________________________________________
Event::Event(Int_t iev, Char_t *name, Char_t *title):
TNamed(name,title),
fM1(1),
fM2(1.),
fN(5),
fH1(nullptr),
fD(new Double_t[fN]), // C++11
fDv()
{

  //printf("Construct object %d %s : %s \n",iev,name,title);
  fH1 = new TH1F(Form("%s_H1",name),Form("%s_H1",title),10,0,10);
  fH1->SetBinContent(iev,1.);
  fDv = { 1000.+iev, 2000.+iev, 3000.+iev, 4000.+iev, 5000.+iev }; // C++11

}

//____________________________________________________________________________
Event::~Event() {

  delete fH1;
  //delete [] fD;

}

//____________________________________________________________________________
int main(int argc, char * argv[]) {

  printf("Code version: %d \n",MyProj::fVersion);

  Event *event;

  Int_t nEvents = 10;

  TFile *f;

  // (1) write objects

  f = new TFile("event.root","recreate");

  for (Int_t i = 0; i < nEvents; i++) {
    event = new Event(i, Form("N%d",i), Form("T%d",i));
    event->Write(Form("Event%d",i));
  }

  f->Close();

  // (2) write TClonesArray of objects

  TClonesArray *fEvents = new TClonesArray("MyProj::Event",10);

  f = new TFile("event_tca.root","recreate");

  TClonesArray &events = *fEvents;
  for (Int_t i = 0; i < nEvents; i++) {
    //event = new(events[i]) Event(i, Form("N%d",i), Form("T%d",i));
    event = new(events[i]) Event(i);
  }

  // this gives the same file size as (1)
  //fEvents->Write();

  fEvents->Write("Events",TObject::kSingleKey);

  f->Close();

  return 0;

}
