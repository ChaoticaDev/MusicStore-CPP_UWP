//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"


using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Interop;

namespace SellMusicApp
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>

	///[Windows::Foundation::Metadata::WebHostHiddenAttribute]
	[Windows::UI::Xaml::Data::Bindable]
	public ref class Item sealed
	{
		Platform::String^  _Title;
		Platform::String^ _TrackName;
		Platform::String^ _TrackAlbum;
		Platform::String^ _TrackArtist;
		event PropertyChangedEventHandler^ _PropertyChanged;


	public:

		Item();
		void OnPropertyChanged(Platform::String^ propertyName)
		{
			PropertyChangedEventArgs^ pcea = ref new  PropertyChangedEventArgs(propertyName);
			_PropertyChanged(this, pcea);
		}

		//Artist Name
		property Platform::String^ TrackName
		{
			Platform::String^ get()
			{
				return this->_TrackName;
			}
			void set(Platform::String^ value)
			{
				this->_TrackName = value;
				OnPropertyChanged("TrackName");
			}
		}


		//Album Name
		property Platform::String^ Title
		{
			Platform::String^ get()
			{
				return this->_Title;
			}
			void set(Platform::String^ value)
			{
				this->_Title = value;
				OnPropertyChanged("Title");
			}
		}


		//Title
		property Platform::String^ TrackAlbum
		{
			Platform::String^ get()
			{
				return this->_TrackAlbum;
			}
			void set(Platform::String^ value)
			{
				this->_TrackAlbum = value;
				OnPropertyChanged("TrackAlbum");
			}
		}


		//Track Owner : Stage name
		property Platform::String^ TrackArtist
		{
			Platform::String^ get()
			{
				return this->_TrackArtist;
			}
			void set(Platform::String^ value)
			{
				this->_TrackArtist = value;
				OnPropertyChanged("TrackArtist");
			}
		}

	};

	[Windows::Foundation::Metadata::WebHostHiddenAttribute]
	public ref class StoreData sealed
	{
		Windows::UI::Xaml::Interop::IBindableObservableVector^  _items;

	public:
		StoreData()
		{
			_items = ref new Platform::Collections::Vector<Item^>();
			Windows::Foundation::Uri^ _baseUri = ref new Windows::Foundation::Uri("ms-appx:///");
			Platform::String^ LONG_LOREM_IPSUM = "";//"Curabitur class aliquam vestibulum nam curae maecenas sed integer cras phasellus suspendisse quisque donec dis praesent accumsan bibendum pellentesque condimentum adipiscing etiam consequat vivamus dictumst aliquam duis convallis scelerisque est parturient ullamcorper aliquet fusce suspendisse nunc hac eleifend amet blandit facilisi condimentum commodo scelerisque faucibus aenean ullamcorper ante mauris dignissim consectetuer nullam lorem vestibulum habitant conubia elementum pellentesque morbi facilisis arcu sollicitudin diam cubilia aptent vestibulum auctor eget dapibus pellentesque inceptos leo egestas interdum nulla consectetuer suspendisse adipiscing pellentesque proin lobortis sollicitudin augue elit mus congue fermentum parturient fringilla euismod feugiat";

		}

		property Windows::UI::Xaml::Interop::IBindableObservableVector^ Items
		{
			Windows::UI::Xaml::Interop::IBindableObservableVector^ get()
			{
				return _items;
			}

		}
	};
	public ref class MainPage sealed
	{

		StoreData^ dataSrc;
	public:
		MainPage();

		property StoreData^ DataSource
		{
			StoreData^ get() { return this->dataSrc; };

		}


	private:
		void ListView_ItemClick(Platform::Object^ sender, Windows::UI::Xaml::Controls::ItemClickEventArgs^ e);
		void ListView_SelectionChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::SelectionChangedEventArgs^ e);
	};
}
