#include <iostream>
#include <wx/wx.h>

#include "wrdc.h"
#include "ocpn_plugin.h"
#include "Slocum.h"
#include "SpotPlot.h"
#include "EnsembleWeatherUI.h"


class EnsembleWeatherManager : public EnsembleWeatherUI
{
  public:

    EnsembleWeatherManager(wxWindow* parent,
                           wxWindowID id = wxID_ANY,
                           const wxString& title = wxT("Ensemble Weather"),
                           const wxPoint& pos = wxDefaultPosition,
                           const wxSize& size = wxSize( 389,62 ),
                           long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL)
    : EnsembleWeatherUI(parent, id, title, pos, size, style) {
        Reset();
        LoadFile("/home/kleeman/Desktop/gridded_gfs_2017-03-22_1203.fcst");
//        LoadFile("/home/kleeman/Desktop/gridded_gefs_2017-03-22_1203.fcst");
    };

    void LoadFile(std::string filename);

    void OnOpenFile(wxCommandEvent& event);

    void OnPrevTimeClick(wxCommandEvent& event);

    void OnNextTimeClick(wxCommandEvent& event);

    void OnPaintSpot(wxPaintEvent& event);

    void OnChartDoubleClick(wxMouseEvent &event);

    void OnSpotDoubleClick(wxMouseEvent &event);

    void Reset();

    void Refresh();

    void Render(wrDC &wrdc, PlugIn_ViewPort &vp);

    int m_time_index;
    int m_lon_index;
    int m_lat_index;
    EnsembleForecast m_fcst;

  private:

    SpotPlot m_spot_plot;
    wxPoint m_recent_double_click_point;
    bool m_need_to_process_double_click;
    WindCircleFactory m_wind_circle_factory;
};
