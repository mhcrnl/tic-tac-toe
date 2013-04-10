#include<gtk/gtk.h>
//Declare items
GtkWidget *window;
GtkWidget *buttons[3][3];
GtkWidget *vbox,*grid;

//initialize items
void gtk_init_items()
{
	//set window
	window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_size_request(window,300,400);
	gtk_window_set_resizable(GTK_WINDOW(window),FALSE);
	
	//set buttons
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
		{
			buttons[i][j]=gtk_button_new();
			gtk_widget_set_size_request(buttons[i][j],100,100);
		}
}

//pack items
void gtk_packing()
{
	vbox=gtk_box_new(GTK_ORIENTATION_VERTICAL,5);
	grid=gtk_grid_new();
	
	gtk_container_add(GTK_CONTAINER(window),vbox);
	gtk_box_pack_start(GTK_BOX(vbox),grid,1,1,10);
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			gtk_grid_attach(GTK_GRID(grid),buttons[i][j],i,j,1,1);

}

//free memory and quit program
void quit()
{
	gtk_main_quit();
}

//mark buttons if clicked
void mark(GtkWidget *button)
{
	char *text=gtk_button_get_label(button);
	if(text==NULL)
	{
		gtk_button_set_label(button,"X");
	}
}
//connect signals
void gtk_init_signals()
{
	g_signal_connect(window,"destroy",quit,NULL);
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			g_signal_connect(buttons[i][j],"clicked",G_CALLBACK(mark),buttons[i][j]);
} 

int main(int argc,char *argv[])
{
	gtk_init(&argc,&argv);
	gtk_init_items();
	gtk_packing();
	gtk_init_signals();
	gtk_widget_show_all(window);
	gtk_main();
}
