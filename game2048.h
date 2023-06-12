#ifndef GAME2048_H
#define GAME2048_H

#include <QObject>
#include <string.h>
#include <QtWidgets/QMessageBox>

using namespace std;

class Game2048: public QObject
{
    Q_OBJECT

      int response;
      int User_updating;
      char control;


    public:
      void display_grid();
      void display_win_screen();
      void display_loser_screen();
      QString get_0_0();
      QString get_0_1();
      QString get_0_2();
      QString get_0_3();
      QString get_1_0();
      QString get_1_1();
      QString get_1_2();
      QString get_1_3();
      QString get_2_0();
      QString get_2_1();
      QString get_2_2();
      QString get_2_3();
      QString get_3_0();
      QString get_3_1();
      QString get_3_2();
      QString get_3_3();
      QString get_score();
      int get_response();
      void set_response(int);


      Q_PROPERTY(QString a_0_0 READ get_0_0 NOTIFY cellChnaged)
      Q_PROPERTY(QString a_0_1 READ get_0_1 NOTIFY cellChnaged)
      Q_PROPERTY(QString a_0_2 READ get_0_2 NOTIFY cellChnaged)
      Q_PROPERTY(QString a_0_3 READ get_0_3 NOTIFY cellChnaged)
      Q_PROPERTY(QString a_1_0 READ get_1_0 NOTIFY cellChnaged)
      Q_PROPERTY(QString a_1_1 READ get_1_1 NOTIFY cellChnaged)
      Q_PROPERTY(QString a_1_2 READ get_1_2 NOTIFY cellChnaged)
      Q_PROPERTY(QString a_1_3 READ get_1_3 NOTIFY cellChnaged)
      Q_PROPERTY(QString a_2_0 READ get_2_0 NOTIFY cellChnaged)
      Q_PROPERTY(QString a_2_1 READ get_2_1 NOTIFY cellChnaged)
      Q_PROPERTY(QString a_2_2 READ get_2_2 NOTIFY cellChnaged)
      Q_PROPERTY(QString a_2_3 READ get_2_3 NOTIFY cellChnaged)
      Q_PROPERTY(QString a_3_0 READ get_3_0 NOTIFY cellChnaged)
      Q_PROPERTY(QString a_3_1 READ get_3_1 NOTIFY cellChnaged)
      Q_PROPERTY(QString a_3_2 READ get_3_2 NOTIFY cellChnaged)
      Q_PROPERTY(QString a_3_3 READ get_3_3 NOTIFY cellChnaged)
      Q_PROPERTY(QString score_qml READ get_score NOTIFY cellChnaged)

      int max;
      int win;
      int score;
      int plus;
      int grid[4][4];
      int bgrid[4][4];

      Game2048():  response(0),User_updating(1),max(0),win(2048),score(0)  ,plus(0) {}

      void logic_flow();
      void game_end_check();
      Q_INVOKABLE void key_press_up();
      Q_INVOKABLE void key_press_down();
      Q_INVOKABLE void key_press_right();
      Q_INVOKABLE void key_press_left();
      Q_INVOKABLE void key_press_undo();
      Q_INVOKABLE void key_press_restart();
      Q_INVOKABLE void key_press_quit();
      void update_grid();
      void reOrganize_grid();
      void invoque_number();
      void PlusGrandeCase();
      void undo();

      int full();
      int move_action();
    signals:
        void cellChnaged();
};

#endif // GAME2048_H
