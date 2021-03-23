#include "RecordTable.h"
#include <iostream>

Result::Result() :score(0), name() {}
Result& Result::operator=(const Result &record)
{
	this->score=record.score;
	memcpy(this->name, record.name, 16*sizeof(Uint16));
	return *this;
}

void RecordTable::itemMenu()
{
	text=TTF_RenderUTF8_Solid(menufont, "CLEAR TABLE", (menu==0) ? SelectedColorText : DefaultColorText);
    dest.x=(cache->w/3-text->w)/2; dest.y=cache->h*13/17;
    Draw_FillCircle(cache, cache->w/19, dest.y+text->h/2, (text->h/2+10), SDL_MapRGB(cache->format, 255, 0, 0));
    Draw_FillCircle(cache, cache->w/19+cache->w*5/22, dest.y+text->h/2,(text->h/2+10), SDL_MapRGB(cache->format, 255, 0, 0));
    for(int i=0; i<7; i++)
    {
    	Draw_Circle(cache, cache->w/19, dest.y+text->h/2, (text->h/2+10)-i, (menu==0) ? SDL_MapRGB(cache->format, 1, 245, 249) : SDL_MapRGB(cache->format, 234, 178, 23));
        Draw_Circle(cache, cache->w/19+cache->w*5/22, dest.y+text->h/2, (text->h/2+10)-i, (menu==0) ? SDL_MapRGB(cache->format, 1, 245, 249) : SDL_MapRGB(cache->format, 234, 178, 23));
    }
    Draw_FillRect(cache, cache->w/19, dest.y-cache->h/108, cache->w*5/22, text->h+cache->h/54, SDL_MapRGB(cache->format, 255, 0, 0));
    for(int i=0; i<7; i++)
    {
    	Draw_HLine(cache, cache->w/19, dest.y-cache->h/108+i, cache->w/19+cache->w*5/22, (menu==0) ? SDL_MapRGB(cache->format, 1, 245, 249) : SDL_MapRGB(cache->format, 234, 178, 23));
    	Draw_HLine(cache, cache->w/19, dest.y+text->h+cache->h/108-i, cache->w/19+cache->w*5/22, (menu==0) ? SDL_MapRGB(cache->format, 1, 245, 249) : SDL_MapRGB(cache->format, 234, 178, 23));
    }
    SDL_BlitSurface(text, NULL, cache, &dest);
    SDL_FreeSurface(text);

    text=TTF_RenderUTF8_Solid(menufont, "PRINT TABLE",(menu == 1) ? SelectedColorText : DefaultColorText);
    dest.x=(cache->w-text->w)/2; dest.y=cache->h*13/17;
    Draw_FillCircle(cache, cache->w/3+cache->w/28, dest.y+text->h/2, (text->h/2+10), SDL_MapRGB(cache->format, 255, 0, 0));
    Draw_FillCircle(cache, cache->w/3+cache->w/28+cache->w/4, dest.y+text->h/2,(text->h/2+10), SDL_MapRGB(cache->format, 255, 0, 0));
    for(int i=0; i<7; i++)
    {
    	Draw_Circle(cache, cache->w/3+cache->w/28, dest.y+text->h/2, (text->h/2+10)-i, (menu==1) ? SDL_MapRGB(cache->format, 1, 245, 249) : SDL_MapRGB(cache->format, 234, 178, 23));
        Draw_Circle(cache, cache->w/3+cache->w/28+cache->w/4, dest.y+text->h/2, (text->h/2+10)-i, (menu==1) ? SDL_MapRGB(cache->format, 1, 245, 249) : SDL_MapRGB(cache->format, 234, 178, 23));
    }
    Draw_FillRect(cache, cache->w/3+cache->w/28, dest.y-cache->h/108, cache->w/4, text->h+cache->h/54, SDL_MapRGB(cache->format, 255, 0, 0));
    for(int i=0; i<7; i++)
    {
    	Draw_HLine(cache, cache->w/3+cache->w/28, dest.y-cache->h/108+i, cache->w/3+cache->w/28+cache->w/4, (menu==1) ? SDL_MapRGB(cache->format, 1, 245, 249) : SDL_MapRGB(cache->format, 234, 178, 23));
    	Draw_HLine(cache, cache->w/3+cache->w/28, dest.y+text->h+cache->h/108-i, cache->w/3+cache->w/28+cache->w/4, (menu==1) ? SDL_MapRGB(cache->format, 1, 245, 249) : SDL_MapRGB(cache->format, 234, 178, 23));
    }
    SDL_BlitSurface(text, NULL, cache, &dest);
    SDL_FreeSurface(text);

    text=TTF_RenderUTF8_Solid(menufont, "MAIN MENU",(menu==2) ? SelectedColorText : DefaultColorText);
    dest.x=(cache->w*3/2)/2; dest.y=cache->h*13/17;
    Draw_FillCircle(cache, cache->w*2/3+cache->w/28, dest.y+text->h/2, (text->h/2+10), SDL_MapRGB(cache->format, 255, 0, 0));
    Draw_FillCircle(cache, cache->w*2/3+cache->w/28+cache->w/4, dest.y+text->h/2,(text->h/2+10), SDL_MapRGB(cache->format, 255, 0, 0));
    for(int i=0; i<7; i++)
    {
    	Draw_Circle(cache, cache->w*2/3+cache->w/28, dest.y+text->h/2, (text->h/2+10)-i, (menu==2) ? SDL_MapRGB(cache->format, 1, 245, 249) : SDL_MapRGB(cache->format, 234, 178, 23));
        Draw_Circle(cache, cache->w*2/3+cache->w/28+cache->w/4, dest.y+text->h/2, (text->h/2+10)-i, (menu==2) ? SDL_MapRGB(cache->format, 1, 245, 249) : SDL_MapRGB(cache->format, 234, 178, 23));
    }
    Draw_FillRect(cache, cache->w*2/3+cache->w/28, dest.y-cache->h/108, cache->w/4, text->h+cache->h/54, SDL_MapRGB(cache->format, 255, 0, 0));
    for(int i=0; i<7; i++)
    {
    	Draw_HLine(cache, cache->w*2/3+cache->w/28, dest.y-cache->h/108+i, cache->w*2/3+cache->w/28+cache->w/4, (menu==2) ? SDL_MapRGB(cache->format, 1, 245, 249) : SDL_MapRGB(cache->format, 234, 178, 23));
    	Draw_HLine(cache, cache->w*2/3+cache->w/28, dest.y+text->h+cache->h/108-i,cache->w*2/3+cache->w/28+cache->w/4, (menu==2) ? SDL_MapRGB(cache->format, 1, 245, 249) : SDL_MapRGB(cache->format, 234, 178, 23));
    }
    SDL_BlitSurface(text, NULL, cache, &dest);
    SDL_FreeSurface(text);
}
RecordTable::RecordTable(SDL_Surface *const &surf): Interface(surf), count(0)
{
	ifstream file("binary.dat");
	for(int i=0; count<10 && file.read(reinterpret_cast<char*>(&result[i]), sizeof(struct Result)); i++) count++;
	file.close();
	
	text = TTF_RenderUTF8_Solid(titlefont, "RECORDS", DefaultColorText);
    dest.x=(cache->w-text->w)/2; dest.y=cache->h/36;
    SDL_BlitSurface(text, NULL, cache, &dest);
    SDL_FreeSurface(text);
    
    itemMenu();
    
    text=TTF_RenderUTF8_Solid(helpfont, "TIP: Use arrows and cursor to select. Click 'Enter' or mouse button to move.", DefaultColorText);
    dest.x=(cache->w-text->w)/2; dest.y=cache->h-text->h-(cache->h/20);
    Draw_FillRect(cache, cache->w/10, dest.y-cache->h/54, cache->w-(cache->w/5), text->h+cache->h/54, SDL_MapRGB(cache->format, 255, 0, 0));
    for(int i=0; i<7; i++)
    {
    	Draw_Rect(cache, cache->w/10-i, dest.y-cache->h/54-i, cache->w-(cache->w/5)+2*i, text->h+cache->h/54+2*i, SDL_MapRGB(cache->format, 234, 178, 23));
    }
    
    SDL_BlitSurface(text, NULL, cache, &dest);
    SDL_FreeSurface(text);
}
RecordTable::~RecordTable()
{
	ofstream file("binary.dat");
	file.write(reinterpret_cast<char*>(result), sizeof(Result)*count);
	file.close();
}
void RecordTable::Show(SDL_Surface *const &surf)
{
	SDL_BlitSurface(cache, NULL, surf, NULL);
	
	char *scoretext;
	char placetext[3];
    dest.y=surf->h*2/13;
    
    text=TTF_RenderUTF8_Solid(recordfont, "Place", DefaultColorText);
    dest.x=(cache->w/4+cache->w*5/16-text->w)/2; dest.y+=(text->h+cache->h/108);
    Draw_FillRect(cache, cache->w/4, dest.y-cache->h/108, cache->w/2, text->h+cache->h/54, SDL_MapRGB(cache->format, 255, 0, 0));
    for(int j=0; j<4; j++)
    {
        Draw_Rect(cache, cache->w/4+j, dest.y-cache->h/108+j, cache->w/2-2*j, text->h+cache->h/54-2*j, SDL_MapRGB(cache->format, 234, 178, 23));
        Draw_VLine(cache, cache->w*5/16-j, dest.y-cache->h/108, dest.y+text->h+cache->h/108, SDL_MapRGB(cache->format, 234, 178, 23));
        Draw_VLine(cache, cache->w*13/20-j, dest.y-cache->h/108, dest.y+text->h+cache->h/108, SDL_MapRGB(cache->format, 234, 178, 23));
    }
    SDL_BlitSurface(text, NULL, surf, &dest);
    SDL_FreeSurface(text);
    
    text=TTF_RenderUTF8_Solid(recordfont,"Player name", DefaultColorText);
    dest.x=surf->w/3;
    SDL_BlitSurface(text, NULL, surf, &dest);
    SDL_FreeSurface(text);
    
    text=TTF_RenderUTF8_Solid(recordfont,"Score", DefaultColorText);
    dest.x=(cache->w*13/20+cache->w/192);
    SDL_BlitSurface(text, NULL, surf, &dest);
    SDL_FreeSurface(text);
    
    for(int i=0; i<count; i++)
    {
        memset(placetext, 0, 3);    // Удаление мусора в массиве
        sprintf(placetext, "%d", i+1);  // Запись в массив (нумерация рекордов)
        text=TTF_RenderText_Solid(recordfont, placetext, DefaultColorText);
        dest.x=(cache->w/4+cache->w*5/16-text->w)/2; dest.y+=(text->h+cache->h/108);
        Draw_FillRect(cache, cache->w/4, dest.y-cache->h/108, cache->w/2, text->h+cache->h/54, SDL_MapRGB(cache->format, 255, 0, 0));
        for(int j=0; j<4; j++)
        {
        	Draw_Rect(cache, cache->w/4+j, dest.y-cache->h/108+j, cache->w/2-2*j, text->h+cache->h/54-2*j, SDL_MapRGB(cache->format, 234, 178, 23));
        	Draw_VLine(cache, cache->w*5/16-j, dest.y-cache->h/108, dest.y+text->h+cache->h/108, SDL_MapRGB(cache->format, 234, 178, 23));
        	Draw_VLine(cache, cache->w*13/20-j, dest.y-cache->h/108, dest.y+text->h+cache->h/108, SDL_MapRGB(cache->format, 234, 178, 23));
        }
        SDL_BlitSurface(text, NULL, surf, &dest);
        SDL_FreeSurface(text);

        text=TTF_RenderUNICODE_Solid(recordfont, result[i].name, DefaultColorText);
        dest.x=surf->w/3;
        SDL_BlitSurface(text, NULL, surf, &dest);
        SDL_FreeSurface(text);
        int min=(int)result[i].score/60;
	    int sec=(int)result[i].score%60;
	    if (min>59)
	    {
	    	min=59;
	    	sec=59;
	    }
	    int j=0;
	    if (min>9) 
	    {
		    scoretext=new char[6];
		    scoretext[1]=(min%10)+'0'; j++; 
		    min/=10;
		    scoretext[0]=(min%10)+'0'; j++;
	    }
	    else
	    {
		    scoretext=new char[5];
		    scoretext[j++]=(min%10)+'0';
	    }
	    scoretext[j++]=':';
	    if(sec>9)
	    {
	    	j++;
		    scoretext[j]=(sec%10)+'0'; 
		    j--;
		    sec/=10;
		    scoretext[j]=(sec%10)+'0';
		    j+=2;
	    }
	    else
	    {
		    scoretext[j++]='0';
		    scoretext[j++]=(sec%10)+'0';
	    }
	    scoretext[j]='\0';
        text=TTF_RenderText_Solid(recordfont, scoretext, DefaultColorText);
        dest.x=(cache->w*13/20+cache->w*3/4)/2;
        SDL_BlitSurface(text, NULL, surf, &dest);
        SDL_FreeSurface(text);
        delete[] scoretext;
    }
}
int RecordTable::KeyEvent(SDL_KeyboardEvent &event)
{
	if(event.type==SDL_KEYDOWN)
    {
        if(event.keysym.sym == SDLK_RIGHT)
        {
            if(menu!=2) menu++;
            else menu = 0; 
            itemMenu();
        }
        if(event.keysym.sym==SDLK_LEFT)
        {
            if(menu!=0) menu--;
            else menu=2;  
            itemMenu();
        }
        if(event.keysym.sym==SDLK_RETURN)
        {
            if(menu==1) Print();
            else if (menu==0) Clear();
            return menu;
        }
    }
    return -1;
}
int RecordTable::MouseMotionEvent(SDL_MouseMotionEvent &motion)
{
	if(motion.type==SDL_MOUSEMOTION)
    {
        if(motion.y>=(cache->h*13/17-cache->h/108) && motion.y<=(cache->h*21/25) && motion.x>(cache->w/19) && motion.x<(cache->w/19+cache->w*5/22))
        {
            menu=0;
            itemMenu();
        }
        if(motion.y>(cache->h*13/17-cache->h/108) && motion.y<=(cache->h*21/25) && motion.x>(cache->w/3+cache->w/28) && motion.x<(cache->w/3+cache->w/28+cache->w/4))
        {
            menu=1;
            itemMenu();
        }
        if(motion.y>(cache->h*13/17-cache->h/108) && motion.y<=(cache->h*21/25) && motion.x>(cache->w*2/3+cache->w/28) && motion.x<(cache->w*2/3+cache->w/28+cache->w/4))
        {
            menu=2;
            itemMenu();
        }
    }
    return -1;
}
int RecordTable::MouseButtonEvent(SDL_MouseButtonEvent &button)
{
	if(button.type==SDL_MOUSEBUTTONDOWN)
    {
        if(menu==1) Print();
        else if(menu==0) Clear();
        return menu;
    }
    return -1;
}
void RecordTable::Clear()
{
	count=0;
}
void RecordTable::Print()
{
	char *txtbuf;
	int min, sec, j=0;
	ofstream file("Record.txt");
    Uint8 str[30];
    for(int i=0; i<count; i++)
    {
        ConvertUTF16toUTF8(&result[i].name[0], 15, str, 30);
        min=(int)(result[i].score/60);
	    sec=(int)(result[i].score%60);
	    if (min>59)
	    {
	    	min=59;
	    	sec=59;
	    }
	    j=0;
	    if (min>9) 
	    {
		    txtbuf=new char[6];
		    txtbuf[1]=(min%10)+'0'; j++; 
		    min/=10;
		    txtbuf[0]=(min%10)+'0'; j++;
	    }
	    else
	    {
		    txtbuf=new char[5];
		    txtbuf[j++]=(min%10)+'0';
	    }
	    txtbuf[j++]=':';
	    if(sec>9)
	    {
	    	j++;
		    txtbuf[j]=(sec%10)+'0'; 
		    j--;
		    sec/=10;
		    txtbuf[j]=(sec%10)+'0';
		    j+=2;
	    }
	    else
	    {
		    txtbuf[j++]='0';
		    txtbuf[j++]=(sec%10)+'0';
	    }
	    txtbuf[j]='\0';
        file <<i+1<<"   "<<str<<"\t"<<txtbuf<< endl;
        delete[] txtbuf;
    }
    file.close();
}
void RecordTable::AddRecord(const double &score, Uint16 *const &playerName)
{
	int i=0;
    while(score<result[i].score && i<count) i++;
    if(count<10) count++; 
    for(int k=count-1; k>i; k--) 
        result[k]=result[k-1];
    result[i].score=score;
    memcpy(result[i].name, playerName, 16*sizeof(Uint16));
}
void RecordTable::ConvertUTF16toUTF8(const Uint16 *sourceStart, const int sourceCount,
                             Uint8 *targetStart, const int targetCount)
{
 	/* Once the bits are split out into bytes of UTF-8, this is a mask OR-ed
    * into the first byte, depending on how many bytes follow.  There are
    * as many entries in this table as there are UTF-8 sequence types.
    * (I.e., one byte sequence, two byte... etc.). Remember that sequencs
    * for *legal* UTF-8 will be 4 or fewer bytes total. */
    static const Uint8 firstByteMark[7] = {0x00, 0x00, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC};
    static const int halfShift  = 10; // ??? ???????? ?? 10 ???
    static const Uint32 halfBase = 0x0010000UL;
    static const Uint32 byteMask = 0xBF;
    static const Uint32 byteMark = 0x80;

    Uint8* targetEnd = targetStart + targetCount;
    const Uint16* sourceEnd = sourceStart + sourceCount;

    const Uint16* source = sourceStart;
    Uint8* target = targetStart;

    while (source < sourceEnd)
    {
        Uint32 ch;
        unsigned short bytesToWrite = 0;

        const Uint16* oldSource = source;
        ch = *source++;

        /* If we have a surrogate pair, convert to UTF32 first. */
        if (ch >= 0xD800u && ch <= 0xDBFFu)
        {
            /* If the 16 bits following the high surrogate are in the source buffer... */
            if (source < sourceEnd)
            {
                Uint32 ch2 = *source;
                /* If it's a low surrogate, convert to UTF32. */
                if (ch2 >= 0xDC00u && ch2 <= 0xDFFFu)
                {
                    ch = ((ch - 0xD800u) << halfShift) + (ch2 - 0xDC00u) + halfBase;
                    ++source;
                }
            } else
            { /* We don't have the 16 bits following the high surrogate. */
                --source; /* return to the high surrogate */
                break;
            }
        }

        /* Figure out how many bytes the result will require */
        if (ch < 0x80u)
        {
            bytesToWrite = 1;
        } else
        if (ch < 0x800u)
        {
            bytesToWrite = 2;
        } else
        if (ch < 0x10000u)
        {
            bytesToWrite = 3;
        } else
        if (ch < 0x110000u)
        {
            bytesToWrite = 4;
        } else
        {
            bytesToWrite = 3;
            ch = 0x0000FFFDu;
        }

        target += bytesToWrite;
        if (target > targetEnd)
        {
            source = oldSource;
            target -= bytesToWrite;
            break;
        }

        switch (bytesToWrite)
        { /* note: everything falls through. */
            case 4: *--target = (Uint8)((ch | byteMark) & byteMask); ch >>= 6;
            case 3: *--target = (Uint8)((ch | byteMark) & byteMask); ch >>= 6;
            case 2: *--target = (Uint8)((ch | byteMark) & byteMask); ch >>= 6;
            case 1: *--target =  (Uint8)(ch | firstByteMark[bytesToWrite]);
        }

        target += bytesToWrite;
    }
}

