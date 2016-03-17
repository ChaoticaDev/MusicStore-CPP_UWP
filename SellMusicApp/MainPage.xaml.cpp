//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace SellMusicApp;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

Item::Item() :_Title(""), _TrackName(""), _TrackAlbum("") {

}

MainPage::MainPage()
{
	InitializeComponent();
	//mediaElement->Play();

	this->dataSrc = ref new StoreData();


	Item^ im = ref new Item();
	im->Title = "Illusions";
	im->TrackAlbum = "Emi McDade: UberSnip Features.";
	im->TrackArtist = "Emi McDade";
	im->TrackName = "https://ubersnip.com/musicio/emimcdade_illusions.mp3";


	Item^ im2 = ref new Item();
	im2->Title = "Can't make you love me";
	im2->TrackAlbum = "Jules M: UberSnip Features.";
	im2->TrackArtist = "Jules M";
	im2->TrackName = "https://ubersnip.com/musicio/julesm_cantmakeyouwantme.mp3";

	this->dataSrc->Items->Append(im);
	this->dataSrc->Items->Append(im2);
}

void SellMusicApp::MainPage::ListView_ItemClick(Platform::Object^ sender, Windows::UI::Xaml::Controls::ItemClickEventArgs^ e)
{
}


void SellMusicApp::MainPage::ListView_SelectionChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::SelectionChangedEventArgs^ e)
{

	Item^ im = dynamic_cast<Item^>(dynamic_cast<ListView^>(sender)->SelectedItem);

	if (im == nullptr) {
		printf("null ptr");
	}
	else {
		mediaElement->Source = ref new Windows::Foundation::Uri(im->TrackName);
		mediaElement->Play();

	}
}
