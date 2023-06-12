#include "game2048.h"
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<cmath>
#include <QtWidgets/QMessageBox>
#include "backuper.h"
#include "initiator.h"
#include "largetscorechecker.h"



using namespace std;

    int Game2048::get_response(){   // method to get response
        return this->response;
    }
    void Game2048::set_response(int response){  // method to set the variable response with the value passed in parameter
        this->response = response;
    }

    QString Game2048::get_score(){  // method to get the score
        return QString::number(score);
    }
/* 16 methods to get the value in the grid [i][j] */
    QString Game2048::get_0_0(){  // method to get the value in the grid [0][0]
        if(grid[0][0]==0)    // if the value equal 0, return the string "" else return the value
            return "";
        return QString::number(grid[0][0]);
    }

    QString Game2048::get_0_1(){
        if(grid[0][1]==0)
            return "";
        return QString::number(grid[0][1]);
    }

    QString Game2048::get_0_2(){
        if(grid[0][2]==0)
            return "";
        return QString::number(grid[0][2]);
    }

    QString Game2048::get_0_3(){
        if(grid[0][3]==0)
            return "";
        return QString::number(grid[0][3]);
    }

    QString Game2048::get_1_0(){
        if(grid[1][0]==0)
            return "";
        return QString::number(grid[1][0]);
    }

    QString Game2048::get_1_1(){
        if(grid[1][1]==0)
            return "";
        return QString::number(grid[1][1]);
    }

    QString Game2048::get_1_2(){
        if(grid[1][2]==0)
            return "";
        return QString::number(grid[1][2]);
    }

    QString Game2048::get_1_3(){
        if(grid[1][3]==0)
            return "";
        return QString::number(grid[1][3]);
    }

    QString Game2048::get_2_0(){
        if(grid[2][0]==0)
            return "";
        return QString::number(grid[2][0]);
    }

    QString Game2048::get_2_1(){
        if(grid[2][1]==0)
            return "";
        return QString::number(grid[2][1]);
    }

    QString Game2048::get_2_2(){
        if(grid[2][2]==0)
            return "";
       return QString::number(grid[2][2]);
    }

    QString Game2048::get_2_3(){
        if(grid[2][3]==0)
            return "";
        return QString::number(grid[2][3]);
    }

    QString Game2048::get_3_0(){
        if(grid[3][0]==0)
            return "";
        return QString::number(grid[3][0]);
    }

    QString Game2048::get_3_1(){
        if(grid[3][1]==0)
            return "";
       return QString::number(grid[3][1]);
    }

    QString Game2048::get_3_2(){
        if(grid[3][2]==0)
            return "";
        return QString::number(grid[3][2]);
    }

    QString Game2048::get_3_3(){
        if(grid[3][3]==0)
            return "";
        return QString::number(grid[3][3]);
    }


/* 7 methods to manage the pressed key (the variable control get a value to know later which key was pressed)*/
    void Game2048::key_press_up()  // method to manage the directionnal key pressed  "up"
    {
      control = 'w';  // letter "w" permitt to know later that the pressed key is "up"
      this->logic_flow();  // call the local method logic_flow to build the new grid and save "the old score"
      this->game_end_check();  // call the local method game_end_check
      cellChnaged();  // call the method cellChnaged
    }
    void Game2048::key_press_down()
    {
      control = 's';
      this->logic_flow();
      this->game_end_check();
      cellChnaged();
    }
    void Game2048::key_press_right()
    {
      control = 'd';
      this->logic_flow();
      this->game_end_check();
      cellChnaged();
    }
    void Game2048::key_press_left()
    {
      control = 'a';
      this->logic_flow();
      this->game_end_check();
      cellChnaged();
    }

    void Game2048::key_press_undo()
    {
      control = 'u';
      this->logic_flow();
      this->game_end_check();
      cellChnaged();
    }

    void Game2048::key_press_restart()
    {
      control = 'r';
      this->logic_flow();
      this->game_end_check();
      cellChnaged();
    }

    void Game2048::key_press_quit()
    {
      control = 'q';
      this->logic_flow();
      this->game_end_check();
      cellChnaged();
    }

    void Game2048::logic_flow()
    {
      Backuper backuper;  // instance the class Backuper
      Initiator initiator;  // instance the class Initiator
      LargetScoreChecker largestScoreChecker;  // instance the class LargetScoreChecker

      switch(control)
      {
          case 'w':   // cases where pressed key is "up" or "left" or "down" or "right"
          case 'a':
          case 's':
          case 'd':
              backuper.backup_grid(this->bgrid, this->grid);  // save the grid in bgrid
              this->update_grid(); // update the grid just with the same adjacents cells and calculate the new score
              this->reOrganize_grid();  // update the grid with the others cells
              largestScoreChecker.plusGrandeCase(this->grid, &(this->max)); // max has the max value of the grid

              if(this->full()&&User_updating)  // if the grid is full and no adjacents cells haved the same value
              {
                  response=-1;  // response has the value -1
                  break;
              }
              else if(this->move_action())  // else if the new grid is different of the old grid (bgrid)
              {
                  this->invoque_number();  // a new 2 or 4 is putted on a free cell
                  break;
              }
              else
              {
                  response=0;  // response has the value 0
                  break;
              }

          case 'u':   // player want to get the previous grid
              if(this->move_action())  // call the method move_action()
                score-=plus;  // score have the previous score
              this->undo();  // call the method undo()
              break;


          case 'r':   // player want to play a new game
                initiator.init(this->grid, this->score, this->max);  // call the method initiator.init
                score=0;  // reinitialize the value of score
                max=0;  // reinitialize the value of max
                break;

          case 'q':  // player want to quit the game
              response=-1;  // response has the value -1
              break;
      }
    }

    void Game2048::game_end_check()
    {
      if(max==win)
      {
        this->display_win_screen();

      }

      else if(response==-1)
      {
        this->display_loser_screen();
      }
    }

    void Game2048::reOrganize_grid()  // use after update_grid; manage the other cells and update the grid
    {

        switch(control)
        {
            case 'w':
                        for(int i=0;i<4;i++)  // browse the grid on the good direction in fonction of the pressed key
                            for(int j=0;j<4;j++)
                            {
                                if(!grid[j][i])  // if the value is 0, we have to up shift the cells on this column i
                                {
                                    for(int k=j+1;k<4;k++)
                                        if(grid[k][i])  // up shift this cell when the value is not 0
                                        {
                                            grid[j][i]=grid[k][i]; // the up cell take the value of the bottom cell
                                            grid[k][i]=0;  // the bottom cell take the value 0
                                            break;
                                        }
                                }

                            }break;

            case 's':
                        for(int i=0;i<4;i++)  // browse the grid on the good direction in fonction of the pressed key
                            for(int j=3;j>=0;j--)
                            {
                                if(!grid[j][i])  // if the value is 0, we have to down shift the cells on this column i
                                {
                                    for(int k=j-1;k>=0;k--)
                                        if(grid[k][i])  // down shift this cell when the value is not 0
                                        {
                                            grid[j][i]=grid[k][i];  // the down cell take the value of the up cell
                                            grid[k][i]=0;  // the up cell take the value 0
                                            break;
                                        }
                                }

                            }break;
            case 'a':
                        for(int i=0;i<4;i++)  // browse the grid on the good direction in fonction of the pressed key
                            for(int j=0;j<4;j++)
                            {
                                if(!grid[i][j])  // if the value of this cell is 0, we have to left shift the cells on this line i
                                {
                                    for(int k=j+1;k<4;k++)
                                        if(grid[i][k])  // left shift this cell when the value is not 0
                                        {
                                            grid[i][j]=grid[i][k]; // the left cell take the value of the right cell
                                            grid[i][k]=0;  // the right cell take the value 0
                                            break;
                                        }
                                }

                            }break;


            case 'd':
                        for(int i=0;i<4;i++)  // browse the grid on the good direction in fonction of the pressed key
                            for(int j=3;j>=0;j--)
                            {
                                if(!grid[i][j])  // if the value of this cell is 0, we have to right shift the cells on this line i
                                {
                                    for(int k=j-1;k>=0;k--)
                                        if(grid[i][k])  // right shift this cell when the value is not 0
                                        {
                                            grid[i][j]=grid[i][k];  // the right cell take the value of the left cell
                                            grid[i][k]=0;  // the left cell take the value 0
                                            break;
                                        }
                                }

                            }break;

        }
    }


    void Game2048::update_grid()  // update the grid (manage just the same adjacents cells) and calculate the new score and the difference between the new score and the old score
    {
        plus=0;  // difference between the new score and the old score (use with the key undo is pressed)
        User_updating=1;  // variable of control ; use with test of grid full

        switch(control)
        {
            case 'w':
                        for(int i=0;i<4;i++)
                            for(int j=0;j<3;j++)
                            {
                                if(grid[j][i]&&grid[j][i]==grid[j+1][i])  // if the two cells (on top and bottom) have the same value (different of 0)
                                {
                                    User_updating=0;
                                    grid[j][i]+=grid[j+1][i];  // the first (on top) cell double its value
                                    grid[j+1][i]=0;   // the second (bottom) cell take the value 0
                                    plus+=(((log2(grid[j][i]))-1)*grid[j][i]);  // calculate and add the points on the variable plus
                                    score+=(((log2(grid[j][i]))-1)*grid[j][i]);  // calculate and add the points at the new score

                                }
                            }break;

            case 's':
                        for(int i=0;i<4;i++)
                            for(int j=3;j>0;j--)
                            {
                                if(grid[j][i]&&grid[j][i]==grid[j-1][i])  // if the two cells (bottom and on top) have the same value (different of 0)
                                {
                                    User_updating=0;
                                    grid[j][i]+=grid[j-1][i];  // the first (bottom) cell double its value
                                    grid[j-1][i]=0;   // the second (on top) cell take the value 0
                                    plus+=(((log2(grid[j][i]))-1)*grid[j][i]);  // calculate and add the points on the variable plus
                                    score+=(((log2(grid[j][i]))-1)*grid[j][i]);  // calculate and add the points at the new score
                                }
                            }break;

            case 'a':
                        for(int i=0;i<4;i++)
                            for(int j=0;j<3;j++)
                            {
                                if(grid[i][j]&&grid[i][j]==grid[i][j+1])  // if the two cells (left and right) have the same value (different of 0)
                                {
                                    User_updating=0;
                                    grid[i][j]+=grid[i][j+1];  // the first (on left) cell double its value
                                    grid[i][j+1]=0;  // the second (on right) cell take the value 0
                                    plus+=((log2(grid[i][j]))-1)*grid[i][j];  // calculate and add the points on the variable plus
                                    score+=((log2(grid[i][j]))-1)*grid[i][j];  // calculate and add the points at the new score
                                }
                            }break;

            case 'd':
                        for(int i=0;i<4;i++)
                            for(int j=4;j>0;j--)
                            {
                                if(grid[i][j]&&grid[i][j]==grid[i][j-1])  // if the two cells (right and left) have the same value (different of 0)
                                {
                                    User_updating=0;
                                    grid[i][j]+=grid[i][j-1];  // the first (on right) cell double its value
                                    grid[i][j-1]=0;  // the second (on left) cell take the value 0
                                    plus+=((log2(grid[i][j]))-1)*grid[i][j];  // calculate and add the points on the variable plus
                                    score+=(((log2(grid[i][j]))-1)*grid[i][j]);  // calculate and add the points at the new score
                                }
                            }break;
        }
    }


    void Game2048::invoque_number()  // get a value (2 or 4) in a free cell (its value is 0)
    {
            int i,j,k;
            do                                     // choose a free cell
            {
                i=Initiator::random_index(4);
                j=Initiator::random_index(4);
            }while(grid[i][j]);  // repeat until the cell is free

            k=Initiator::random_index(10);  // choose the value 2 or 4 for the cell
            if(k<1)            // 90% : generate 2 , 10% : generate 4
                grid[i][j]=4;

            else
                grid[i][j]=2;
    }


    int Game2048::full()  // return 1 if the grid is full or 0 else
    {
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
            {
                if(!grid[i][j])
                    return 0;
            }
    return 1;
    }

    void Game2048::undo()  // grid has the previous values on bgrid
    {
            for(int i=0;i<4;i++)
                for(int j=0;j<4;j++)
                    grid[i][j]=bgrid[i][j];
    }

    int Game2048::move_action()  // return 1 if the new grid is different of the old grid and 0 else
    {
        int k=0;

        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                if(bgrid[i][j]!=grid[i][j])
                {
                    k=1;
                    break;
                }
    return k;
    }

    /****************************************Displays***********************************/

    void Game2048::display_win_screen()   // display a message of victory and ask if the user want to play again
    {
        cellChnaged();
        QMessageBox msgBox;  // instance a QMessageBox
        msgBox.setText("You win!");  //set the text
        msgBox.setInformativeText("Do you want to replay?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::Yes);
        int ret = msgBox.exec();
        switch (ret) {
          case QMessageBox::Yes:
              response=0;
              this->key_press_restart();  // the user want to play again so call of the method key_press_restart
              break;
          case QMessageBox::No:  // the user don't want to play again. So exit
              exit(0);

          default:   // for a answer different of yes or no, call of the method key_press_restart to play again
              response=0;
              this->key_press_restart();
              break;
        }
    }

    void Game2048::display_loser_screen() // display a message of victory and ask if the user want to play again
    {
        QMessageBox msgBox;  // instance a QMessageBox
        msgBox.setText("You lost!");    //set the text
        msgBox.setInformativeText("Do you want to replay?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::Yes);
        int ret = msgBox.exec();
        switch (ret) {
          case QMessageBox::Yes:
              response=0;
              this->key_press_restart();  // the user want to play again so call of the method key_press_restart
              break;

          case QMessageBox::No:  // the user don't want to play again. So exit
              exit(0);

          default:    // for a answer different of yes or no, call of the method key_press_restart to play again
              response=0;
              this->key_press_restart();
              break;
        }
    }


