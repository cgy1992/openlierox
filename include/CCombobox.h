/////////////////////////////////////////
//
//             Liero Xtreme
//
//     Copyright Auxiliary Software 2002
//
//
/////////////////////////////////////////


// Combo box
// Created 3/9/02
// Jason Boettcher


#ifndef __CCOMBOBOX_H__
#define __CCOMBOBOX_H__


// Combo box events
enum {
	CMB_NONE=-1,
	CMB_CHANGED
};

// Combobox messages
enum {
	CBM_ADDITEM,
	CBM_ADDSITEM,
	CBM_GETCOUNT,
	CBM_GETCURINDEX,
	CBM_GETCURSINDEX,
	CBM_GETCURITEM,
    CBM_GETCURNAME,
	CBM_CLEAR,
	CBM_SETCURSEL,
    CBM_SETCURSINDEX,
    CBM_SETCURINDEX,
	CBM_SETIMAGE,
	CBM_ISDROPPED
};


// Item structure
typedef struct cb_item_s {
	int			iIndex;
	char		sIndex[256];
	char		sName[128];
	int			iSelected;
	SDL_Surface *tImage;

	struct	cb_item_s	*tNext;

} cb_item_t;



class CCombobox : public CWidget {
public:
	// Constructor
	CCombobox() {
		tItems = NULL;
		tSelected = NULL;
		iItemCount = 0;
		iGotScrollbar = false;
		iDropped = false;
		iArrowDown = false;
        iLastDropped = false;
		iDropTime = 0;
		iNow = 0;
		iCanSearch = true;
		iKeySelectedItem = -1;

	}


private:
	// Attributes

	// Items
	cb_item_t		*tItems;
	cb_item_t		*tSelected;
	int				iItemCount;
	int				iGotScrollbar;
	int				iDropped;
	int				iArrowDown;
    int             iLastDropped;
	int				iDropTime;
	int				iNow;
	int				iKeySelectedItem;

	// Stuff
	int				iCanSearch;

	// Scrollbar
	CScrollbar		cScrollbar;


public:
	// Methods

	void	Create(void);
	void	Destroy(void);

	//These events return an event id, otherwise they return -1
	int		MouseOver(mouse_t *tMouse);
	int		MouseUp(mouse_t *tMouse, int nDown);
	int		MouseDown(mouse_t *tMouse, int nDown);
	int		MouseWheelDown(mouse_t *tMouse);
	int		MouseWheelUp(mouse_t *tMouse);
	int		KeyUp(int c)					{ iCanSearch = true; return CMB_NONE; }
	int		KeyDown(int c);

	void	Draw(SDL_Surface *bmpDest);

	int		SendMessage(int iMsg, DWORD Param1, DWORD Param2);	

    void    clear(void);
	void	addItem(int index, char *sindex, char *name);	
	void	setCurItem(int index);
    void    setCurSIndexItem(char *szString);
    void    setCurIndexItem(int nIndex);
	void	setImage(SDL_Surface *img, int ItemIndex);
	int		getDropped(void) { return iDropped; }
};


#endif  //  __CCOMBOBOX_H__
