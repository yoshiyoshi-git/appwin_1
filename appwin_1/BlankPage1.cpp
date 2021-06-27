#include "pch.h"
#include "BlankPage1.h"
#if __has_include("BlankPage1.g.cpp")
#include "BlankPage1.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::appwin_1::implementation
{
    BlankPage1::BlankPage1()
    {
        InitializeComponent();
    }

    void BlankPage1::OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs const& e)
    {
        //BlankPage1起動時はe.Parameter() == nullptrです。そのときは何もしない。
        if (e.Parameter() == nullptr)
            return;

        auto propertyValue{ e.Parameter().as < Windows::Foundation::IPropertyValue>() };

        if (propertyValue.Type() == Windows::Foundation::PropertyType::String)
            blank1_text().Text(winrt::unbox_value<winrt::hstring>(e.Parameter()));
        else
            blank1_text().Text(L"文字列じゃないよ！");
    }
}


void winrt::appwin_1::implementation::BlankPage1::send_Mainpage_navi_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
{
    mainFrame.Navigate(xaml_typename<appwin_1::MainPage>(), winrt::box_value(L"ぶらんく1からめいんぺ～～～～じへ"));
}


void winrt::appwin_1::implementation::BlankPage1::send_Mainpage_global_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
{
    pmain_string->DataString(L"ぶらんく1からめいんぺ～～～～じへ");
}


void winrt::appwin_1::implementation::BlankPage1::send_Mainpage_mem_func_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
{
    auto mainpage = MainPage::GetMainCurrent();
    mainpage.SetMainText(L"ぶらんく1からめいんぺ～～～～じへ はんどるから！！");
}
