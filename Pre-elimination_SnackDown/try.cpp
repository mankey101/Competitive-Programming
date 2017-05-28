#include <bits/stdc++.h>
using namespace std;
int main(){
        int t;
	cin>>t;
	   for(int blah=0; blah<t; blah++){
                int n;
		cin>>n;
		string up[2];
		cin>>up[0]>>up[1];
            int ui = 0;
            int di = 0;
            bool DEB=true;
            while(ui<n && up[0].charAt(ui)=='.' ) ui++; //find first occurances of #
            while(di<n && up[1].charAt(di)=='.') di++;
            if(DEB) printf("\t>>>>ui: "+ui+" di: "+di);
            if(ui==di) {
                // of type: ....#blah
                //          ....#blah
                while(ui<n && (up[0][ui] == up[1][ui]) && (up[0][ui]=='#')) {ui++; di++;}
                // ui == di still
                // ..#####blah
                // ..#####blah
                while(ui<n && (up[0][ui] == up[1][ui]) && (up[0][ui]=='.')) {ui++; di++;}
                // ui == di still

                // ..#####...
                // ..#####...
                if(ui==n) {printf("yes");if(DEB) printf("\t>>>>ui==n");}
                // ..#####...#  ; ..####...
                // ..#####...#  ; ..####..#
                else if(up[0][ui-1]!='#' && up[1][ui-1]!='#'){
                    if(DEB) printf("\t>>>>up[0].charAt(ui-1)!='#' && up[1].charAt(ui-1)!='#'");
                    printf("no"); continue;
                }
                // ..###.blah
                // ..####blah
                else if(up[1][ui-1]=='#'){ //CARE index out of bound ERRORS HERE
                    //Note in first cell, there is no # beneath it. (case covered above)
                    if(DEB) printf("\t>>>>up[1].charAt(ui-1)=='#'");
                    int entry = 0; // 0->Horiz, 1: Vert;
                    int read = 1; // 0 : UP, 1: low
                    ui=di; ui++;  // ui is significant variable
                    //  Incase it ends here.
                    //
                    if(ui==n) {printf("yes"); continue TEST;}
                    while(true){
                        if(ui==n) {printf("yes"); continue TEST;}
                        if(up[read][ui]=='.') break;
                        // ##blah
                        // .#blah
                        else if(up[(read+1)%2][ui]=='#') {read=((read+1)%2); entry = 1; ui++;}
                        else{
                            ui++;
                        }

                    }   //NAVIGATING LOOP
                    //Now check if any # remaining.
                    while(ui<n && (up[0][ui] == up[1][ui])) && (up[0][ui]=='.')) {ui++;}
                    if(ui==n) {printf("yes"); continue TEST;}
                    else {printf("no"); continue TEST;}
                } //else if ends
                // ..####blah
                // ..###. blah
                else if(up[0][ui-1]=='#'){
                    //Note in first cell, there is no # beneath it. (case covered above)
                    int entry = 0; // 0->Horiz, 1: Vert;
                    int read = 0; // 0 : UP, 1: low
                    ui++; di=ui; // ui is significant variable
                    //  Incase it ends here.
                    //
                    if(ui==n) {printf("yes"); continue TEST;}
                    while(true){
                        if(ui==n) {printf("yes"); continue TEST;}
                        if(up[read][ui]=='.') break;
                        // ##blah
                        // .#blah
                        else if(up[(read+1)%2][ui]=='#') {read=((read+1)%2); entry = 1; ui++;}
                        else{
                            ui++;
                        }

                    }   //NAVIGATING LOOP
                    //Now check if any # remaining.
                    while(ui<n && (up[0][ui] == up[1][ui]) && (up[0][ui]=='.')) {ui++;}
                    if(ui==n) {printf("yes"); continue TEST;}
                    else {printf("no"); continue TEST;}
                }
            } //ui == di
            else if(ui < di){ //# found first in upper string.
                //Note in first cell, there is no # beneath it. (case covered above)
                int entry = 0; // 0->Horiz, 1: Vert;
                int read = 0; // 0 : UP, 1: low
                ui++; di=ui; // ui is significant variable
                //  Incase it ends here.
                //
                if(ui==n) {printf("yes"); continue TEST;}
                while(true){
                    if(ui==n) {printf("yes"); continue TEST;}
                    if(up[read][ui]=='.') break;
                    // ##blah
                    // .#blah
                    else if(up[(read+1)%2][ui]=='#') {read=((read+1)%2); entry = 1; ui++;}
                    else{
                        ui++;
                    }

                }   //NAVIGATING LOOP
                //Now check if any # remaining.
                while(ui<n && (up[0][ui] == up[1].charAt[ui]) && (up[0][ui]=='.')) {ui++;}
                if(ui==n) {printf("yes"); continue TEST;}
                else {printf("no"); continue TEST;}


            }
            else if(ui > di){
                //Note in first cell, there is no # beneath it. (case covered above)
                int entry = 0; // 0->Horiz, 1: Vert;
                int read = 1; // 0 : UP, 1: low
                ui=di; ui++; ; // di is significant variable
                //  Incase it ends here.
                //
                if(ui==n) {printf("yes"); continue TEST;}
                while(true){
                    if(ui==n) {printf("yes"); continue TEST;}
                    if(up[read][ui]=='.') break;
                    // ##blah
                    // .#blah
                    else if(up[(read+1)%2][ui]=='#') {read=((read+1)%2); entry = 1; ui++;}
                    else{
                        ui++;
                    }

                }   //NAVIGATING LOOP
                //Now check if any # remaining.
                while(ui<n && (up[0][ui] == up[1][ui]) && (up[0][ui]=='.')) {ui++;}
                if(ui==n) {printf("yes"); continue TEST;}
                else {printf("no"); continue TEST;}
            }
        }//test loop

    } //main


