#include <windows.h>
#include "resource.h"
#include <locale.h>
#include <CommDlg.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <wchar.h>

using namespace std;

HWND ghDlg = 0;
HWND h_edit, Edit;
HWND Dialog2, Dialog3, Dialog4, Dialog5, Dialog6;
HWND g1, g2, g3, g4, g5, g6, g7, g8, g9, g10, g11, g12, g13, g14, g15,
g16, g17, g18, g19, g20, g21, g22, g23, g24, g25, g26, g27, g28, g29, g30,
g31, g32, g33, g34, g35, g36, g37, g38, g39, g40;
HWND a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15,
a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30,
a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45,
a46, a47, a48;
HWND h_combobox, h_listbox1, h_listbox2, h_listbox3, h_listbox4;
HWND hPictureControl;
HMENU hMenu;
HINSTANCE hInstance;
HBITMAP hBitmap1, hBitmap2, hBitmap3, hBitmap4;
wchar_t buffer[256];
wchar_t contador1[200000], contador2[200000], contador3[200000], contador4[200000], contador5[200000], ArchivoUsuario[100];
char archivousuario[100];
int a, b, c, d;
float fe;
bool nuevo, regresar, nuevous, confirmar, QUICK;
wofstream myfile("CarneT.txt");
wofstream myfile2("QuickSort.txt");
wofstream myfile3("HeapSort.txt");
struct usuarios {
    wchar_t clavusuario[50], nombrecom[170], contraseña[50], paterno[50], materno[50], nombres[50];
    int numusuario;
    bool NewUsuario;

    usuarios* siguiente;
    usuarios* anterior;
};
struct pacientes {
    wchar_t paterno[50], materno[50], nombres[50], nombrecom[170], CURP[20], RFC[20], nacimiento[30], calle[50], colonia[50],
        ciudad[50], estado[50], edocivil[50], telefono[11], DdI[100], sexo[10], GO[50], PR[50];
    int numpaciente;

   pacientes* siguiente;
   pacientes* anterior;
};
struct vacunas {
    wchar_t /*nomvacuna[50], */tipo[50], marca[50], clavacuna[50], descripcion[150];
    float precio = 0;
    
    int dosis, numvacunas;
    vacunas* siguiente;
    vacunas* anterior;
};
struct carnes {
    wchar_t ID[50], carpaciente[50], carvacuna[50], fecha[50], lote[50], centro[50];
    float total = 0;
    int cardosis,numcarnes;

    carnes* siguiente;
    carnes* anterior;
};

usuarios* actual = nullptr;
usuarios* buscar1 = new usuarios();
usuarios* lista1 = NULL;
usuarios* contar1 = new usuarios();
usuarios* validar1 = new usuarios();
usuarios* guardar1 = new usuarios();

pacientes* buscar2 = new pacientes();
pacientes* lista2 = NULL;
pacientes* contar2 = new pacientes();
pacientes* validar2 = new pacientes();

vacunas* lista3 = NULL;
vacunas* buscar3 = new vacunas();
vacunas* contar3 = new vacunas();
vacunas* validar3 = new vacunas();


carnes* lista4 = NULL;
carnes* buscar4 = new carnes();
carnes* contar4 = new carnes();

char menu0, menu1, menu2, menu3, sinoadmin, sinoactivo;
bool UsuValid, adminuevusu, comernew, Cvalid;
int CV1, CV2, CV3, CV4, CV5;
int i = 0;
//j = usuario actual
int j = 0;

//k = numero de usuarios
int k = 0;

//l = numero de comercios
int l = 0;

//m = numero de pacientes
int m = 0;

//n = numero de vacunas
int n = 0;

//o = numero de carnes
int o = 0;

int clavei = 0;
//wchar_t clavew;

wchar_t Usuario[50], Contraseña[50];
wchar_t Validar1[] = L"0123456789", Validar2[] = L"!#$%&=()='?¡¿@´¨*+{[]}-_<>~", Validar3[] = L"abcdefghijklmnñopqrstuvwxyz", Validar4[] = L"ABCDEFGHIJKLMNÑOPQRSTUVWXYZ";

wchar_t Buscar_Usuario[50];
wchar_t Buscar_Paciente[50];
wchar_t Buscar_Vacuna[50];
wchar_t Buscar_Carne[50];
wchar_t Paciente_Carne[50];
wchar_t Vacuna_Carne[50];
wchar_t Carne_Paciente[50];

float producto;
//Lista ligada Usuarios
wchar_t clavusu[50], nomcom[170], cont[50]; int numusu; bool newus;

//Lista Ligada Pacientes
wchar_t pater[50], mater[50], nombs[50], nomc[170], curp[20], rfc[20], nacim[30], call[50], col[50], cid[50], edo[50], edociv[50], tel[11], ddi[100], sex[10], go[50], pr[50], img[100]; int numpac = 0;

//Lista ligada Vacunas
wchar_t nomvac[50], tip[50], marc[50], clavac[50], desc[100]; float price = 0; int dos = 0;


//Lista ligada Carnes
wchar_t id[50], carpa[50], carvac[50], date[50], lot[50], cent[50]; float tot; int cardos;

//usuario
wchar_t clavusuarioq[20], contrasena[20], unombre[50], upaterno[50], umaterno[20], unombres[50]; int cantus = 0;

//paciente
wchar_t pacienteq[50], ppaterno[50], pmaterno[20], pnombres[50], CURP[50], RFC[50], nacimiento[20], calle[50], colonia[50], ciudad[50], estado[50], edocivil[50], telefono[10], DdI[50], sexo[10], GO[50], PR[50]; int cantclien = 0;
wchar_t direccion[220], gopro[110];

//vacuna
wchar_t vacunaq[50], tipo[50], marca[50], clavacuna[50], descripcion[50], dosi[50], preci[10000]; int cantprom = 0;

//carne
wchar_t carneq[50], carvacuna[20], fechacar[20], lote[50], centro[50], total[20]; int cantcons = 0;

//wchar_t ValidCont[];

wchar_t PH[250];

//Ventanas-----------------------------------------------------------------------------------------------------------------------
BOOL CALLBACK WindowProc1(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK WindowProc2(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK WindowProc3(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK WindowProc4(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK WindowProc5(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK WindowProc6(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
//Lista--
BOOL CALLBACK Lista1(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Lista2(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Lista3(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Lista4(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
//Usuario--
BOOL CALLBACK RegistroUsuario(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ActualizarUA(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK NuevUsuario(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ResCon(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ResConAct(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Actusu(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ActusuB1(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
//Pacientes--
BOOL CALLBACK ActPac(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK NuevPaciente(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
//Vacunas--
BOOL CALLBACK ActVacuna(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK NuevVacuna(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
//Carne--
BOOL CALLBACK NuevCarne(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ActCar(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Carne(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Total(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Confirmar(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

void ContadorMaestro(HWND hwnd) {
    k = 0, m = 0, n = 0, o = 0;
    contar1 = lista1;
    while (contar1 != nullptr) {
        k++;
        contar1 = contar1->siguiente;
    }
    contar2 = lista2;
    while (contar2 != nullptr) {

        m++;
        contar2 = contar2->siguiente;
    }
    contar3 = lista3;
    while (contar3 != nullptr) {
        n++;
        contar3 = contar3->siguiente;
    }
    contar4 = lista4;
    while (contar4 != nullptr) {
        o++;
        contar4 = contar4->siguiente;
    }

    if (k != 0) {
        k--;
    }
    if (m != 0) {
        m--;
    }
    if (n != 0) {
        n--;
    }
    if (o != 0) {
        o--;
    }

   // k--, m--, n--, o--;
}

void ContraValid(HWND hwnd, wchar_t cont[50]) {
    Cvalid = false;
    CV1 = 0, CV2 = 0;
    while (CV1 < 10) {
        CV2 = 0;
        while (CV2 < 27) {
            if (cont[CV1] == Validar3[CV2]) {

                Cvalid = true;
                CV1 = 10;
                CV2 = 27;
            }
            else {
                Cvalid = false;
            }
            CV2++;
        }
        CV1++;
    }
    if (Cvalid == true) {
        CV1 = 0, CV2 = 0;
        while (CV1 < 10) {
            CV2 = 0;
            while (CV2 < 10) {
                if (cont[CV1] == Validar1[CV2]) {

                    Cvalid = true;
                    CV1 = 10;
                    CV2 = 10;
                }
                else {
                    Cvalid = false;
                }
                CV2++;
            }
            CV1++;
        }
    }
    if (Cvalid == true) {
        CV1 = 0, CV2 = 0;
        while (CV1 < 10) {
            CV2 = 0;
            while (CV2 < 27) {
                if (cont[CV1] == Validar2[CV2]) {

                    Cvalid = true;
                    CV1 = 10;
                    CV2 = 27;
                }
                else {
                    Cvalid = false;
                }
                CV2++;
            }
            CV1++;
        }
    }

}
void VANUMSIM(HWND hwnd, wchar_t PH[250]) {
    Cvalid = false;
    CV1 = 0;
    while ((PH[CV1] != L'\0') && (CV1 < 250)) {
        CV2 = 0;
        while (CV2 < 10) {
            CV3 = 0;
            while (CV3 < 27) {
                if ((PH[CV1] == Validar1[CV2]) || (PH[CV1] == Validar2[CV3])) {

                    Cvalid = false;
                    CV1 = 250;
                    CV2 = 10;
                    CV3 = 27;
                }
                else {
                    Cvalid = true;
                }
                CV3++;
            }
            CV2++;
        }
        CV1++;
    }
}
void VASIM(HWND hwnd, wchar_t PH[250]) {
    Cvalid = false;
    CV1 = 0;
    while ((PH[CV1] != L'\0') && (CV1 < 250)) {
        CV3 = 0;
        while (CV3 < 27) {
            if (PH[CV1] == Validar2[CV3]) {
                Cvalid = false;
                CV1 = 250;
                CV3 = 27;
            }
            else {
                Cvalid = true;
            }
            CV3++;
        }
        CV1++;
    }
}
//Archivos-----------------------------------------------------------------------------------------------------------------------

void AbrirU(HWND hwnd) {
    usuarios* abrir = new usuarios;
    fstream Archivo;
    Archivo.open("Usuarios.txt", ios::in | ios::binary);
    if (Archivo.is_open()) {
        /* Archivo.read(reinterpret_cast<char*>(k), sizeof(k));*/
        int i = 0, size = Archivo.tellg();
        usuarios* Aux = nullptr;
        while (Archivo.good()) {
            Aux = new usuarios;
            ZeroMemory(Aux, sizeof(usuarios));
            Archivo.seekg(i * sizeof(usuarios));
            Archivo.read(reinterpret_cast<char*>(Aux), sizeof(usuarios));
            i++;
            if (lista1 == nullptr) {
                lista1 = Aux;
                lista1->siguiente = nullptr;
                abrir = lista1;

            }
            else {
                /*if (wcscmp(Aux->contraseña, L"") == 0) {

                }
                else {*/
                abrir = lista1;
                while (abrir->siguiente != nullptr) {
                    abrir = abrir->siguiente;
                }
                abrir->siguiente = Aux;
                abrir->siguiente->siguiente = nullptr;
                abrir = abrir->siguiente;
                /*}*/
            }
        }
        MessageBox(NULL, TEXT("Usuarios cargados"), TEXT("Archivo"), MB_ICONINFORMATION);
    }
    else {
        MessageBox(NULL, TEXT("No se pudo abrir el archivo de usuarios"), TEXT("Archivo"), MB_ICONEXCLAMATION);
    }

    
}
void GuardarU(HWND hwnd) {
    usuarios* guardar = new usuarios;
    fstream Archivo;
    Archivo.open("Usuarios.txt", ios::out | ios::trunc | ios::binary);
    if (Archivo.is_open()) {
        //Archivo.write(reinterpret_cast<char*>(k), sizeof(k));
        guardar = lista1;
        while (guardar != nullptr) {
            Archivo.write(reinterpret_cast<char*>(guardar), sizeof(usuarios));
            guardar = guardar->siguiente;


        }
        //Archivo << lista1->nomusuario;


        MessageBox(NULL, TEXT("Usuarios guardados"), TEXT("Archivo"), MB_ICONINFORMATION);
    }
    else {
        MessageBox(NULL, TEXT("No se pudo guardar el archivo de usuarios"), TEXT("Archivo"), MB_ICONEXCLAMATION);
    }
    Archivo.close();

}

void AbrirPac(HWND hwnd) {
    pacientes* abrir = new pacientes;


    fstream Archivo;
    Archivo.open("Pacientes.txt", ios::in | ios::binary);
    if (Archivo.is_open()) {

        int i = 0, size = Archivo.tellg();
        pacientes* Aux = nullptr;
        while (Archivo.good()) {
            Aux = new pacientes;
            ZeroMemory(Aux, sizeof(pacientes));

            Archivo.seekg(i * sizeof(pacientes));
            Archivo.read(reinterpret_cast<char*>(Aux), sizeof(pacientes));
            i++;
            if (lista2 == nullptr) {
                lista2 = Aux;
                lista2->siguiente = nullptr;
                abrir = lista2;

            }
            else {
                /*if (wcscmp(Aux->contraseña, L"") == 0) {

                }
                else {*/
                abrir = lista2;
                while (abrir->siguiente != nullptr) {
                    abrir = abrir->siguiente;
                }
                abrir->siguiente = Aux;
                abrir->siguiente->siguiente = nullptr;
                abrir = abrir->siguiente;
                /*}*/
            }



        }
        MessageBox(NULL, TEXT("Pacientes cargados"), TEXT("Archivo"), MB_ICONINFORMATION);
    }
    else {
        MessageBox(NULL, TEXT("No se pudo abrir el archivo de pacientes"), TEXT("Archivo"), MB_ICONEXCLAMATION);
    }
}
void GuardarPac(HWND hwnd) {
    pacientes* guardar = new pacientes;



    fstream Archivo;
    Archivo.open("Pacientes.txt", ios::out | ios::trunc | ios::binary);
    if (Archivo.is_open()) {

        guardar = lista2;
        while (guardar != nullptr) {
            Archivo.write(reinterpret_cast<char*>(guardar), sizeof(pacientes));
            guardar = guardar->siguiente;


        }


        MessageBox(NULL, TEXT("Pacientes guardados"), TEXT("Archivo"), MB_ICONINFORMATION);
    }
    else {
        MessageBox(NULL, TEXT("No se pudo guardar el archivo de pacientes"), TEXT("Archivo"), MB_ICONEXCLAMATION);
    }
    Archivo.close();

}

void AbrirVac(HWND hwnd) {
    vacunas* abrir = new vacunas;


    fstream Archivo;
    Archivo.open("Vacunas.txt", ios::in | ios::binary);
    if (Archivo.is_open()) {

        int i = 0, size = Archivo.tellg();
        vacunas* Aux = nullptr;
        while (Archivo.good()) {
            Aux = new vacunas;
            ZeroMemory(Aux, sizeof(vacunas));

            Archivo.seekg(i * sizeof(vacunas));
            Archivo.read(reinterpret_cast<char*>(Aux), sizeof(vacunas));
            i++;
            if (lista3 == nullptr) {
                lista3 = Aux;
                lista3->siguiente = nullptr;
                abrir = lista3;

            }
            else {
               
                abrir = lista3;
                while (abrir->siguiente != nullptr) {
                    abrir = abrir->siguiente;
                }
                abrir->siguiente = Aux;
                abrir->siguiente->siguiente = nullptr;
                abrir = abrir->siguiente;
                
            }



        }
        MessageBox(NULL, TEXT("Vacunas cargados"), TEXT("Archivo"), MB_ICONINFORMATION);
    }
    else {
        MessageBox(NULL, TEXT("No se pudo abrir el archivo de vacunas"), TEXT("Archivo"), MB_ICONEXCLAMATION);
    }
}
void GuardarVac(HWND hwnd) {
    vacunas* guardar = new vacunas;



    fstream Archivo;
    Archivo.open("Vacunas.txt", ios::out | ios::trunc | ios::binary);
    if (Archivo.is_open()) {

        guardar = lista3;
        while (guardar != nullptr) {
            Archivo.write(reinterpret_cast<char*>(guardar), sizeof(vacunas));
            guardar = guardar->siguiente;


        }


        MessageBox(NULL, TEXT("Vacunas guardados"), TEXT("Archivo"), MB_ICONINFORMATION);
    }
    else {
        MessageBox(NULL, TEXT("No se pudo guardar el archivo de vacunas"), TEXT("Archivo"), MB_ICONEXCLAMATION);
    }
    Archivo.close();

}

void AbrirCar(HWND hwnd) {
    carnes* abrir = new carnes;


    fstream Archivo;
    Archivo.open("Carnes.txt", ios::in | ios::binary);
    if (Archivo.is_open()) {

        int i = 0, size = Archivo.tellg();
        carnes* Aux = nullptr;
        while (Archivo.good()) {
            Aux = new carnes;
            ZeroMemory(Aux, sizeof(carnes));

            Archivo.seekg(i * sizeof(carnes));
            Archivo.read(reinterpret_cast<char*>(Aux), sizeof(carnes));
            i++;
            if (lista4 == nullptr) {
                lista4 = Aux;
                lista4->siguiente = nullptr;
                abrir = lista4;

            }
            else {

                abrir = lista4;
                while (abrir->siguiente != nullptr) {
                    abrir = abrir->siguiente;
                }
                abrir->siguiente = Aux;
                abrir->siguiente->siguiente = nullptr;
                abrir = abrir->siguiente;

            }



        }
        MessageBox(NULL, TEXT("Carnes cargados"), TEXT("Archivo"), MB_ICONINFORMATION);
    }
    else {
        MessageBox(NULL, TEXT("No se pudo abrir el archivo de carnes"), TEXT("Archivo"), MB_ICONEXCLAMATION);
    }
}
void GuardarCar(HWND hwnd) {
   carnes* guardar = new carnes;



    fstream Archivo;
    Archivo.open("Carnes.txt", ios::out | ios::trunc | ios::binary);
    if (Archivo.is_open()) {

        guardar = lista4;
        while (guardar != nullptr) {
            Archivo.write(reinterpret_cast<char*>(guardar), sizeof(carnes));
            guardar = guardar->siguiente;


        }


        MessageBox(NULL, TEXT("Carnes guardados"), TEXT("Archivo"), MB_ICONINFORMATION);
    }
    else {
        MessageBox(NULL, TEXT("No se pudo guardar el archivo de carnes"), TEXT("Archivo"), MB_ICONEXCLAMATION);
    }
    Archivo.close();

}

void AbrirCont(HWND hwnd) {

    struct contadores
    {
        int l;
    };


    fstream Archivo;
    Archivo.open("contador.txt", ios::in | ios::binary);
    if (Archivo.is_open()) {



        int size = Archivo.tellg();

        int i = 0;
        contadores* Temp = new contadores;
        Archivo.seekg(i * sizeof(contadores));
        Archivo.read(reinterpret_cast<char*>(Temp), sizeof(contadores));

        //contadores lista;
        /*lista.*/l = Temp->l;

        //delete Temp;



    }

}
void GuardarCont(HWND hwnd) {

    struct contadores
    {
        int l;
    };


    contadores* guardar = new contadores;
    guardar->l = l;

    fstream Archivo;
    Archivo.open("contador.txt", ios::out | ios::trunc | ios::binary);
    if (Archivo.is_open()) {
        //guardar = elemento;
        Archivo.write(reinterpret_cast<char*>(guardar), sizeof(contadores));



    }

    Archivo.close();

}

void AbrirImagen(HWND hwnd) {
    OPENFILENAME ofn;

    TCHAR zFile[MAX_PATH]; //260 caracteres

    ZeroMemory(&ofn, sizeof(ofn));

    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = hwnd;
    ofn.lpstrFilter = TEXT("ALL\0 * .*\0Bitmaps\0 * .bmp\0");
    ofn.lpstrFile = zFile;
    ofn.lpstrFile[0] = '\0';
    ofn.nMaxFile = sizeof(zFile);
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
    ofn.nFilterIndex = 2;

    if (GetOpenFileName(&ofn) == TRUE) {
        wcscpy_s(img, ofn.lpstrFile);
    }
    else {
        wcscpy_s(img, L"Perfil.bmp");
    }

}

//Main---------------------------------------------------------------------------------------------------------------------------
int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PWSTR pCmdLine, _In_ int nCmdShow)
{
    /*wcscpy_s(usu, L"usuario 0");
    wcscpy_s(nomcom, L"Usuario Numero Cero");
    wcscpy_s(cont, L"contrasena 0");
    wcscpy_s(comer, L"comercio 0");
    wcscpy_s(ali, L"Usuario No. 0");
    wcscpy_s(img, L"Perfil.bmp");
    numcom = 0;
    adm = true;
    newus = false;

    agregar_usuario(lista1, usu, nomcom, cont, comer, ali, numcom, adm, newus, img);*/
    setlocale(LC_ALL, "spanish");
    ghDlg = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), 0, (DLGPROC)WindowProc1);
    ShowWindow(ghDlg, nCmdShow);
    MSG msg;
    ZeroMemory(&msg, sizeof(MSG));
    while (GetMessage(&msg, 0, 0, 0))
    {
        if (ghDlg == 0 || !IsDialogMessage(ghDlg, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    return (int)msg.wParam;
}
//WindowProc---------------------------------------------------------------------------------------------------------------------
BOOL CALLBACK WindowProc1(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

    switch (uMsg)
    {
    case WM_CREATE:
    case WM_INITDIALOG:
        /* g14 = NULL;
         g15 = NULL;*/
        g1 = NULL;
        g2 = NULL;
        hMenu = LoadMenu(hInstance, MAKEINTRESOURCE(IDR_MENU1));
        SetMenu(hwnd, hMenu);

        g1 = GetDlgItem(hwnd, IDC_EDIT1);
        SetWindowText(g1, L"usuario");

        g2 = GetDlgItem(hwnd, IDC_EDIT2);
        SetWindowText(g2, L"contraseña");

        break;

    case WM_COMMAND:

        switch (LOWORD(wParam)) {
        case ID_ARCHIVO_ABRIR:
            lista1 = NULL; k = 0;
            AbrirU(hwnd);
            ContadorMaestro(hwnd);
            /*AbrirPac(hwnd);*/
            ///*AbrirP(hwnd);
            //AbrirCo(hwnd);*/
            //AbrirCont(hwnd);
           // ContadorMaestro(hwnd);
            break;
        case ID_ARCHIVO_GUARDAR:
            GuardarU(hwnd);
            //GuardarPac(hwnd);
            ///*GuardarP(hwnd);
            //GuardarCo(hwnd);*/
            GuardarCont(hwnd);
            break;

        case ID_SALIR_GUARDARYSALIR:
            GuardarU(hwnd);
           // GuardarPac(hwnd);
            ////GuardarP(hwnd);
            ////GuardarCo(hwnd);
            GuardarCont(hwnd);
            //DestroyWindow(hwnd);
            //DestroyMenu(hMenu);
            //DestroyWindow(ghDlg);
            break;
        case ID_SALIR_SALIRSINGUARDAR:
            DestroyWindow(hwnd);
            DestroyMenu(hMenu);
            DestroyWindow(ghDlg);
            break;
        case IDC_BUTTON1:

            GetWindowText(g1, (LPWSTR)clavusuarioq, sizeof(clavusuarioq));
            GetWindowText(g2, (LPWSTR)contrasena, sizeof(contrasena));
            wcscpy_s(Usuario, clavusuarioq);
            wcscpy_s(Contraseña, contrasena);
            UsuValid = false;
            actual = lista1;
            j = 0;
            while ((actual != nullptr) && ((wcscmp(Usuario, actual->clavusuario) != 0) || (wcscmp(Contraseña, actual->contraseña) != 0))) {

                actual = actual->siguiente;
                //j++;
            }

            if (actual != nullptr) {
                UsuValid = true;
            }

            if (UsuValid == true) {
                if (actual->NewUsuario == true) {
                    DialogBox(NULL, MAKEINTRESOURCE(IDD_DATAUSU), hwnd, (DLGPROC)ActualizarUA);
                    if (regresar == false) {
                       
                        Dialog2 = CreateDialog(NULL, MAKEINTRESOURCE(IDD_DIALOG2), hwnd, (DLGPROC)WindowProc2);
                        ShowWindow(Dialog2, SW_SHOW);
                    }
                }
                else {
                    Dialog2 = CreateDialog(NULL, MAKEINTRESOURCE(IDD_DIALOG2), hwnd, (DLGPROC)WindowProc2);
                    ShowWindow(Dialog2, SW_SHOW);
                }

            }

            else if (UsuValid == false) {
                MessageBox(hwnd, L"Usuario y/o contraseña incorrectos.", L"Aviso", MB_ICONEXCLAMATION);
            }
            break;
        case IDC_BUTTON2:

            DialogBox(NULL, MAKEINTRESOURCE(IDD_REGISTRO), hwnd, (DLGPROC)RegistroUsuario);

            break;
        case IDC_BUTTON3:


            DestroyWindow(hwnd);


            break;


        }
        break;
    case WM_CLOSE:

        DestroyWindow(hwnd);
        DestroyMenu(hMenu);
        DestroyWindow(ghDlg);
        return 0;

    case WM_DESTROY:

        PostQuitMessage(0);
        break;

    }

    return FALSE;

}
BOOL CALLBACK WindowProc2(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg)
    {
    case WM_CREATE:
    case WM_INITDIALOG:

        a1 = GetDlgItem(hwnd, IDC_STATIC1);
        SetWindowText(a1, actual->clavusuario);
        a2 = GetDlgItem(hwnd, IDC_STATIC2);
        SetWindowText(a2, actual->nombres);
        a3 = GetDlgItem(hwnd, IDC_STATIC3);
        
        SetWindowText(a3, actual->paterno);
        
        a30 = GetDlgItem(hwnd, IDC_STATIC9);
        SetWindowText(a30, actual->materno);

        /*hPictureControl = GetDlgItem(hwnd, IDC_PICTUREC);
        hBitmap2 = (HBITMAP)LoadImage(NULL, actual->imagen, IMAGE_BITMAP, 100, 100, LR_LOADFROMFILE);
        SendDlgItemMessage(hwnd, IDC_PICTUREC, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap2);*/

        a20 = GetDlgItem(hwnd, IDC_STATIC4);

        a21 = GetDlgItem(hwnd, IDC_STATIC5);

        a22 = GetDlgItem(hwnd, IDC_STATIC6);

        a23 = GetDlgItem(hwnd, IDC_STATIC7_);

        a24 = GetDlgItem(hwnd, IDC_STATIC8);

        /*Contador(hwnd);
        _itow_s(a, contador1, 200000, 10);
        SetWindowText(a20, contador1);
        _itow_s(b, contador2, 200000, 10);
        SetWindowText(a21, contador2);
        _itow_s(c, contador3, 200000, 10);
        SetWindowText(a22, contador3);
        _itow_s(d, contador4, 200000, 10);
        SetWindowText(a23, contador4);
        swprintf_s(contador5, L"%.1f", fe);
        SetWindowText(a24, contador5);*/

        break;


    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case ID_ARCHIVO_ABRIR:
           // BorrarLista1(lista1);
            lista1 = NULL; k = 0;
            lista2 = NULL; m = 0;
            lista3 = NULL; n = 0;
            lista4 = NULL; o = 0;
            AbrirU(hwnd);
            AbrirPac(hwnd);
            AbrirVac(hwnd);
            AbrirCar(hwnd);
            AbrirCont(hwnd);
            ContadorMaestro(hwnd);
            break;
        case ID_ARCHIVO_GUARDAR:
            GuardarU(hwnd);
            GuardarPac(hwnd);
            GuardarVac(hwnd);
            GuardarCar(hwnd);
            GuardarCont(hwnd);
            break;
        case ID_SALIR_GUARDARYSALIR:
            GuardarU(hwnd);
           /* GuardarCl(hwnd);
            GuardarP(hwnd);
            GuardarCo(hwnd);*/
            GuardarCont(hwnd);
            DestroyWindow(hwnd);
            DestroyMenu(hMenu);
            DestroyWindow(ghDlg);
            break;
        case ID_SALIR_SALIRSINGUARDAR:
            DestroyWindow(hwnd);
            DestroyMenu(hMenu);
            DestroyWindow(ghDlg);
            break;
        case IDC_BUTTON1:
            
            Dialog3 = CreateDialog(NULL, MAKEINTRESOURCE(IDD_DIALOG3), hwnd, (DLGPROC)WindowProc3);
            ShowWindow(Dialog3, SW_SHOW);

            //SetWindowText(a1, actual->nombrecom);

           
            break;
        case IDC_BUTTON2:
           
            Dialog4 = CreateDialog(NULL, MAKEINTRESOURCE(IDD_DIALOG4), hwnd, (DLGPROC)WindowProc4);
            ShowWindow(Dialog4, SW_SHOW);
            break;
        case IDC_BUTTON3:
            Dialog5 = CreateDialog(NULL, MAKEINTRESOURCE(IDD_DIALOG4), hwnd, (DLGPROC)WindowProc5);
            ShowWindow(Dialog5, SW_SHOW);
            
            break;
        case IDC_BUTTON4:
           
            Dialog6 = CreateDialog(NULL, MAKEINTRESOURCE(IDD_DIALOG4), hwnd, (DLGPROC)WindowProc6);
            ShowWindow(Dialog6, SW_SHOW);
            break;
        case IDC_BUTTON5:

            
            DestroyWindow(hwnd);



            break;
        case IDC_BUTTON6:
            DeleteObject((HBITMAP)hBitmap2);
            EndDialog(hwnd, wParam);
            DestroyWindow(hwnd);
            DestroyMenu(hMenu);
            DestroyWindow(ghDlg);

            break;
        case IDC_BUTTON7:


            SetWindowText(a1, actual->nombrecom);

           /* SetWindowText(a2, actual->comercio);

            if (actual->Admin == true) {
                SetWindowText(a3, L"Admin: Si");
            }
            else {
                SetWindowText(a3, L"Admin: No");
            }*/
           /* SetWindowText(a30, actual->nombrecom);
            hBitmap2 = (HBITMAP)LoadImage(NULL, actual->imagen, IMAGE_BITMAP, 100, 100, LR_LOADFROMFILE);
            SendDlgItemMessage(hwnd, IDC_PICTUREC, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap2);*/

            /*Contador(hwnd);*/
           /* _itow_s(a, contador1, 200000, 10);
            SetWindowText(a20, contador1);
            _itow_s(b, contador2, 200000, 10);
            SetWindowText(a21, contador2);
            _itow_s(c, contador3, 200000, 10);
            SetWindowText(a22, contador3);
            _itow_s(d, contador4, 200000, 10);
            SetWindowText(a23, contador4);
            swprintf_s(contador5, L"%.1f", fe);
            SetWindowText(a24, contador5);*/

            break;

        }
        break;
    case WM_CLOSE:

        DestroyWindow(hwnd);
        DestroyMenu(hMenu);
        DestroyWindow(ghDlg);
        break;

    }

    return FALSE;
}
BOOL CALLBACK WindowProc3(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg)
    {
    case WM_CREATE:
    case WM_INITDIALOG:
        a27 = GetDlgItem(hwnd, IDC_STATIC1);
        SetWindowText(a27, actual->nombrecom);

       /* hPictureControl = GetDlgItem(hwnd, IDC_PICTUREC);
        hBitmap2 = (HBITMAP)LoadImage(NULL, actual->imagen, IMAGE_BITMAP, 100, 100, LR_LOADFROMFILE);
        SendDlgItemMessage(hwnd, IDC_PICTUREC, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap2);*/

        break;


    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case ID_ARCHIVO_ABRIR:
            lista1 = NULL; k = 0;
            AbrirU(hwnd);
            AbrirCont(hwnd);
            ContadorMaestro(hwnd);
            break;
        case ID_ARCHIVO_GUARDAR:
            GuardarU(hwnd);
            GuardarCont(hwnd);
            break;
        case ID_SALIR_GUARDARYSALIR:
            GuardarU(hwnd);
            /*GuardarCl(hwnd);
            GuardarP(hwnd);
            GuardarCo(hwnd);*/
            GuardarCont(hwnd);
            DestroyWindow(hwnd);
            DestroyMenu(hMenu);
            DestroyWindow(ghDlg);
            break;
        case ID_SALIR_SALIRSINGUARDAR:
            DestroyWindow(hwnd);
            DestroyMenu(hMenu);
            DestroyWindow(ghDlg);
            break;
        case IDC_BUTTON1: //Actualizar Usuario

            DialogBox(NULL, MAKEINTRESOURCE(IDD_DATAUSU), hwnd, (DLGPROC)ActualizarUA);

            SetWindowText(a27, actual->nombrecom);


            /*hBitmap2 = (HBITMAP)LoadImage(NULL, actual->imagen, IMAGE_BITMAP, 100, 100, LR_LOADFROMFILE);
            SendDlgItemMessage(hwnd, IDC_PICTUREC, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap2);*/
            break;
        case IDC_BUTTON2: //Alta de Nuevo Usuario
            
                DialogBox(NULL, MAKEINTRESOURCE(IDD_NEWUSUARIO), hwnd, (DLGPROC)NuevUsuario);
         
            break;
        case IDC_BUTTON3: //Listado de Usuarios
         
                DialogBox(NULL, MAKEINTRESOURCE(IDD_LISTA), hwnd, (DLGPROC)Lista1);
                if (regresar == false) {
                    DialogBox(NULL, MAKEINTRESOURCE(IDD_SELEC), hwnd, (DLGPROC)Actusu);
                }

                SetWindowText(a27, actual->nombrecom);


                /*hBitmap2 = (HBITMAP)LoadImage(NULL, actual->imagen, IMAGE_BITMAP, 100, 100, LR_LOADFROMFILE);
                SendDlgItemMessage(hwnd, IDC_PICTUREC, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap2);*/
        
            break;
        case IDC_BUTTON4: //Restablecer Contraseña
          
                DialogBox(NULL, MAKEINTRESOURCE(IDD_DIALOG4), hwnd, (DLGPROC)ResCon);
           
            break;
        case IDC_BUTTON5:

            DestroyWindow(hwnd);

            break;
        }
        break;
    case WM_CLOSE:

        DestroyWindow(hwnd);
        DestroyMenu(hMenu);
      
        break;

    }

    return FALSE;
}
BOOL CALLBACK WindowProc4(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    /*wchar_t CLASS_NAME[] = L"Menú de clientes";*/
    switch (uMsg)
    {
    case WM_CREATE:
    case WM_INITDIALOG:

        /*h_edit = GetDlgItem(hwnd, IDD_DIALOG4);
        SetWindowText(h_edit, L"Menú de clientes");*/
        h_edit = GetDlgItem(hwnd, IDC_STATIC1);
        SetWindowText(h_edit, L"<Opciones de pacientes>");
        h_edit = GetDlgItem(hwnd, IDC_STATIC4);
        SetWindowText(h_edit, L"Seleccione una opción");
        h_edit = GetDlgItem(hwnd, IDC_BUTTON1);
        SetWindowText(h_edit, L"Alta de Pacientes");
        h_edit = GetDlgItem(hwnd, IDC_BUTTON2);
        SetWindowText(h_edit, L"Listado de Pacientes");

        a28 = GetDlgItem(hwnd, IDC_STATIC2);
        SetWindowText(a28, actual->nombrecom);

        /*hPictureControl = GetDlgItem(hwnd, IDC_PICTUREC);
        hBitmap2 = (HBITMAP)LoadImage(NULL, actual->imagen, IMAGE_BITMAP, 100, 100, LR_LOADFROMFILE);
        SendDlgItemMessage(hwnd, IDC_PICTUREC, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap2);*/

        break;


    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case ID_ARCHIVO_ABRIR:
            lista2 = NULL; m = 0;
            AbrirPac(hwnd);
            AbrirCont(hwnd);
            ContadorMaestro(hwnd);
            break;
        case ID_ARCHIVO_GUARDAR:
            GuardarPac(hwnd);
            break;
        case ID_ARCHIVO_GUARDARCOMO:
            //Guardar(hwnd);
            break;
        case ID_SALIR_GUARDARYSALIR:
            GuardarU(hwnd);
            /*GuardarCl(hwnd);
            GuardarP(hwnd);
            GuardarCo(hwnd);*/
            GuardarCont(hwnd);
            DestroyWindow(hwnd);
            DestroyMenu(hMenu);
            DestroyWindow(ghDlg);
            break;
        case ID_SALIR_SALIRSINGUARDAR:
            DestroyWindow(hwnd);
            DestroyMenu(hMenu);
            DestroyWindow(ghDlg);
            break;

        case IDC_BUTTON1: //Alta de clientes
            nuevo = true;
            DialogBox(NULL, MAKEINTRESOURCE(IDD_NEWPAC), hwnd, (DLGPROC)NuevPaciente);

            break;
        case IDC_BUTTON2: //Listado de clientes
            if (m != 0) {
                nuevo = false;

                DialogBox(NULL, MAKEINTRESOURCE(IDD_LISTAHQ), hwnd, (DLGPROC)Lista2);
                if (regresar == false) {
                    DialogBox(NULL, MAKEINTRESOURCE(IDD_SELEC2), hwnd, (DLGPROC)ActPac);
                }
                break;
            }
            else {
                MessageBox(hwnd, L"No hay Pacientes registrados", L"Aviso", MB_ICONEXCLAMATION);
            }
            break;
        case IDC_BUTTON5:
            DestroyWindow(hwnd);


            break;

        }
        break;
    case WM_CLOSE:

        DestroyWindow(hwnd);
        DestroyMenu(hMenu);
        DestroyWindow(ghDlg);
        break;

    }

    return FALSE;
}
BOOL CALLBACK WindowProc5(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg)
    {
    case WM_CREATE:
    case WM_INITDIALOG:
        h_edit = GetDlgItem(hwnd, IDC_STATIC1);
        SetWindowText(h_edit, L"<Opciones de vacunas>");
        h_edit = GetDlgItem(hwnd, IDC_STATIC4);
        SetWindowText(h_edit, L"Seleccione una opción");
        h_edit = GetDlgItem(hwnd, IDC_BUTTON1);
        SetWindowText(h_edit, L"Alta de Vacunas");
        h_edit = GetDlgItem(hwnd, IDC_BUTTON2);
        SetWindowText(h_edit, L"Listado de Vacunas");

        a29 = GetDlgItem(hwnd, IDC_STATIC2);
        SetWindowText(a29, actual->nombrecom);

        

        break;


    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case ID_ARCHIVO_ABRIR:
            lista3 = NULL; n = 0;
            AbrirVac(hwnd);
            ContadorMaestro(hwnd);
            break;
        case ID_ARCHIVO_GUARDAR:
            GuardarVac(hwnd);
            break;
        case ID_SALIR_GUARDARYSALIR:
            GuardarU(hwnd);
           /* GuardarCl(hwnd);
            GuardarP(hwnd);
            GuardarCo(hwnd);*/
            GuardarCont(hwnd);
            DestroyWindow(hwnd);
            DestroyMenu(hMenu);
            DestroyWindow(ghDlg);
            break;
        case ID_SALIR_SALIRSINGUARDAR:
            DestroyWindow(hwnd);
            DestroyMenu(hMenu);
            DestroyWindow(ghDlg);
            break;
        case IDC_BUTTON1:
           
                nuevo = true;
                DialogBox(NULL, MAKEINTRESOURCE(IDD_NEWVAC), hwnd, (DLGPROC)NuevVacuna);
          
            break;
        case IDC_BUTTON2:
            if (n != 0) {
                nuevo = false;

                DialogBox(NULL, MAKEINTRESOURCE(IDD_LISTA), hwnd, (DLGPROC)Lista3);
                if (regresar == false) {
                    DialogBox(NULL, MAKEINTRESOURCE(IDD_SELEC3), hwnd, (DLGPROC)ActVacuna);
                }
            }
            else {
                MessageBox(hwnd, L"No hay vacunas registrados", L"Aviso", MB_ICONEXCLAMATION);
            }
            break;
        case IDC_BUTTON5:
            DestroyWindow(hwnd);



            break;

        }
        break;
    case WM_CLOSE:

        DestroyWindow(hwnd);
        DestroyMenu(hMenu);
        DestroyWindow(ghDlg);
        break;

    }

    return FALSE;
}
BOOL CALLBACK WindowProc6(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg)
    {
    case WM_CREATE:
    case WM_INITDIALOG:
        h_edit = GetDlgItem(hwnd, IDD_DIALOG4);
        SetWindowText(h_edit, L"Menú de carnes");
        h_edit = GetDlgItem(hwnd, IDC_STATIC1);
        SetWindowText(h_edit, L"<Opciones de carnes>");
        h_edit = GetDlgItem(hwnd, IDC_STATIC4);
        SetWindowText(h_edit, L"Seleccione una opción");
        h_edit = GetDlgItem(hwnd, IDC_BUTTON1);
        SetWindowText(h_edit, L"Alta de Carnes");
        h_edit = GetDlgItem(hwnd, IDC_BUTTON2);
        SetWindowText(h_edit, L"Listado de Carnes");

        a31 = GetDlgItem(hwnd, IDC_STATIC2);
        SetWindowText(a31, actual->nombrecom);

       

        break;


    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case ID_ARCHIVO_ABRIR:
            lista4 = NULL; o = 0;
            AbrirCar(hwnd);
            ContadorMaestro(hwnd);
            ContadorMaestro(hwnd);
            break;
        case ID_ARCHIVO_GUARDAR:
            GuardarCar(hwnd);
            break;
        case ID_SALIR_GUARDARYSALIR:
            GuardarU(hwnd);
            /*GuardarCl(hwnd);
            GuardarP(hwnd);
            GuardarCo(hwnd);*/
            GuardarCont(hwnd);
            DestroyWindow(hwnd);
            DestroyMenu(hMenu);
            DestroyWindow(ghDlg);
            break;
        case ID_SALIR_SALIRSINGUARDAR:
            DestroyWindow(hwnd);
            DestroyMenu(hMenu);
            DestroyWindow(ghDlg);
            break;
        case IDC_BUTTON1:
            nuevo = true;
            DialogBox(NULL, MAKEINTRESOURCE(IDD_NEWCAR), hwnd, (DLGPROC)NuevCarne);
            if (regresar == false) {
                DialogBox(NULL, MAKEINTRESOURCE(IDD_CARNE), hwnd, (DLGPROC)Carne);
            }
            break;
        case IDC_BUTTON2:
            nuevo = false;
            DialogBox(NULL, MAKEINTRESOURCE(IDD_LISTA), hwnd, (DLGPROC)Lista4);
            if (regresar == false) {
                DialogBox(NULL, MAKEINTRESOURCE(IDD_SELEC4), hwnd, (DLGPROC)ActCar);
            }
            break;

        case IDC_BUTTON5:
            DestroyWindow(hwnd);

            break;

        }
        break;
    case WM_CLOSE:

        DestroyWindow(hwnd);
        DestroyMenu(hMenu);
        //DestroyWindow(ghDlg);
        break;

    }

    return FALSE;
}

//Listas--------------------------------------------------------------------------------------------------------------------------
int index;
void listado_usuario(usuarios* lista1) {

    if (lista1 == nullptr) {

    }
    while (lista1 != nullptr) {
        
            SendMessage(h_listbox1, LB_ADDSTRING, (WPARAM)0, (LPARAM)lista1->clavusuario);
        
            lista1 = lista1->siguiente;

    }

}
void listado_pacientes(pacientes* lista2) {

    if (lista2 == nullptr) {
        SendMessage(h_listbox2, LB_ADDSTRING, (WPARAM)0, (LPARAM)L"No hay pacientes registrados");
    }
    while (lista2 != nullptr) {
        
            //SendMessage(h_listbox2, LB_ADDSTRING, (WPARAM)0, (LPARAM)lista2->nombrecom);
        SendMessage(h_listbox2, LB_ADDSTRING, (WPARAM)0, (LPARAM)lista2->CURP);
        lista2 = lista2->siguiente;

    }

}
void listado_vacunas(vacunas* lista3) {
    if (lista3 == nullptr) {
        SendMessage(h_listbox3, LB_ADDSTRING, (WPARAM)0, (LPARAM)L"No hay vacunas registradas");
    }

    while (lista3 != nullptr) {
       
            SendMessage(h_listbox3, LB_ADDSTRING, (WPARAM)0, (LPARAM)lista3->clavacuna);
        
        lista3 = lista3->siguiente;

    }

}
void listado_carnes(carnes* lista4) {
    if (lista4 == nullptr) {
        SendMessage(h_listbox4, LB_ADDSTRING, (WPARAM)0, (LPARAM)L"No hay carnes registrados");
    }

    while (lista4 != nullptr) {
       
            SendMessage(h_listbox4, LB_ADDSTRING, (WPARAM)0, (LPARAM)lista4->ID);
        
        lista4 = lista4->siguiente;

    }

}
void listado_carpaciente(carnes* lista4) {
    if (lista4 == nullptr) {
        SendMessage(h_listbox4, LB_ADDSTRING, (WPARAM)0, (LPARAM)L"No hay carnes para este comercio");
    }

    while (lista4 != nullptr) {
        if (wcscmp(buscar2->CURP, lista4->carpaciente) == 0) {
            SendMessage(h_listbox4, LB_ADDSTRING, (WPARAM)0, (LPARAM)lista4->ID);
        }
        lista4 = lista4->siguiente;

    }

}

carnes* findMid(carnes* inicio, carnes* fin)
{
    carnes* slow = inicio;
    carnes* fast = inicio->siguiente;

    while (fast != fin)
    {
        fast = fast->siguiente;
        if (fast != fin) {
            slow = slow->siguiente;
            fast = fast->siguiente;
        }
    }

    return slow;
}
bool buscarlistaBinaria(carnes* inicio, carnes* fin, wchar_t Buscar_Carne[50])
{
    if (inicio == fin) {
        cout << "No se encontro el numero";
        return false;
    }

    buscar4 = findMid(inicio, fin);

    if (buscar4 != NULL) {
        if (buscar4->ID == Buscar_Carne) {
            cout << "Valor encontrado";
            return true;
        }

        if (buscar4->ID > Buscar_Carne) {
            return buscarlistaBinaria(inicio, buscar4, Buscar_Carne);
        }

        return buscarlistaBinaria(buscar4->siguiente, fin, Buscar_Carne);
    }
    cout << "No se encontro el numero";
    return false;
}



//Quick&HeapSort-----------------------------------------------------------------------------------------------------------------------
int size_arr, first, last;
wchar_t** arregloQ; int* arregloH;

void heapify(int* arregloH, int size_arr, int i);
void heapSort(int* arregloH, int size_arr);
int partition(wchar_t** arregloQ, int start, int finish);
void quickSort(wchar_t** arregloQ, int start, int end);
void swap(int& a, int& b);
void printQ(wchar_t** arregloQ, int size_arr);
void printH(int* arregloH, int size_arr);

void ArregloPQ(pacientes* lista2) {
    pacientes* aux = lista2;  // lista_carnet es el inicio del nodo de carnet
    

    delete[] arregloQ;
    size_arr = 0;  // Para saber cuántos elementos habrá en el arreglo

    while (aux != nullptr) {  // while para sacar cuántos elementos de la lista ligada habrá que pasar a arreglo
        size_arr++;
        aux = aux->siguiente;
    }
    size_arr--;
    aux = lista2;  // Volvemos a igualar el auxiliar al inicio del nodo

    arregloQ = new wchar_t* [size_arr];  // asignamos un puntero a puntero wchar_t para asignar memoria dinámica en el arreglo

    for (int i = 0; i < size_arr; i++) {  // while para meter un elemento del nodo por arreglo
        arregloQ[i] = new wchar_t[255];  // asignamos memoria para la cadena wchar_t
        wcscpy_s(arregloQ[i], 255, aux->CURP);
        aux = aux->siguiente;
    }
    
    
        wofstream myfile2("QuickSort.txt");
        first = 0;
        last = size_arr - 1;
        printQ(arregloQ, size_arr);
        quickSort(arregloQ, first, last);
   
}
void ArregloPH(pacientes* lista2) {
    pacientes* aux = lista2;  //lista_carnet es el inicio del nodo de carnet	
    delete arregloH;
    arregloH = nullptr;
    size_arr = 0;  //Para saber cuantos elementos habrá en el arreglo


    while (aux != nullptr) {  //while para sacar cuantos elementos de la lista ligada habrá que pasar a arreglo

        size_arr++;
        aux = aux->siguiente;
    }

    aux = lista2;  //Volvemos a igualar el auxiliar al inicio del nodo

    arregloH = new int[size_arr];  //asignamos un puntero del tipo para asignar memoria dinámica en el arreglo

    for (int i = 0; i < size_arr; i++) {  //while para meter un elemento del nodo por arreglo

        arregloH[i] = aux->numpaciente;
        aux = aux->siguiente;
    }

    wofstream myfile3("HeapSort.txt");
   
    printH(arregloH, size_arr);
    heapSort(arregloH, size_arr);

}

void heapify(int* arregloH, int size_arr, int i) {
    int left_child = i * 2 + 1;
    int right_child = i * 2 + 2;
    int max_index = i;

    if (left_child < size_arr && arregloH[left_child] > arregloH[max_index]) {
        max_index = left_child;
    }

    if (right_child < size_arr && arregloH[right_child] > arregloH[max_index]) {
        max_index = right_child;
    }

    if (max_index != i) {
        swap(arregloH[i], arregloH[max_index]);

        heapify(arregloH, size_arr, max_index);
    }

}
void heapSort(int* arregloH, int size_arr) {
    for (int i = size_arr / 2 - 1; i >= 0; i--) {
        heapify(arregloH, size_arr, i);
    }

    for (int i = size_arr - 1; i >= 0; i--) {
        swap(arregloH[0], arregloH[i]);
        printH(arregloH, size_arr);
        heapify(arregloH, i, 0);
    }
}

int partition(wchar_t** arregloQ, int first, int last) {
    wstring pivot = arregloQ[last];
    int i = (first - 1);
    for (int j = first; j <= last; j++) {
        if (arregloQ[j] < pivot) {
            i++;
            swap(arregloQ[i], arregloQ[j]);
        }
    }
    swap(arregloQ[i + 1], arregloQ[last]);
    return (i + 1);
}
void quickSort(wchar_t** arregloQ, int first, int last) {
    if (first < last) {
        int pi = partition(arregloQ, first, last);
        quickSort(arregloQ, first, pi - 1);
        quickSort(arregloQ, pi + 1, last);
        printQ(arregloQ, last + 1);
    }
}

void swap(int& a, int& b)
{
    int temp = b;
    b = a;
    a = temp;
}
void printQ(wchar_t** arregloQ, int size_arr) {
    // wofstream myfile2("QuickSort.txt");

    for (int i = 0; i < size_arr; i++) {
        myfile2 << arregloQ[i] << " ";
    }
    myfile2 << endl;

}
void printH(int* arregloH, int size_arr) {
    // wofstream myfile2("QuickSort.txt");

    for (int i = 0; i < size_arr; i++) {
        myfile3 << arregloH[i] << " ";
    }
    myfile3 << endl;

}
//--------------------------------------------------------------------------------------------------------------------------------

BOOL CALLBACK Lista1(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg)
    {
    case WM_CREATE:
    case WM_INITDIALOG:
        /*if (lista == 1) {*/
        h_edit = GetDlgItem(hwnd, IDC_STATIC1);
        SetWindowText(h_edit, L"<Listado de usuarios>");

        h_edit = GetDlgItem(hwnd, IDC_STATIC2);
        SetWindowText(h_edit, L"Seleccione un usuario");

       /* h_edit = GetDlgItem(hwnd, IDC_STATIC3);
        SetWindowText(h_edit, actual->comercio);*/
        h_listbox1 = GetDlgItem(hwnd, IDC_LIST1);
       /* SendMessage(h_listbox1, LB_ADDSTRING, (WPARAM)0, (LPARAM)clavusuarioq);*/

        listado_usuario(lista1);

        break;


    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDC_BUTTON1:
           
            buscar1 = lista1;
            wcscpy_s(Buscar_Usuario, L"NULL");
            index = SendDlgItemMessage(hwnd, IDC_LIST1, LB_GETCURSEL, 0, 0);
            SendDlgItemMessage(hwnd, IDC_LIST1, LB_GETTEXT, index, (LPARAM)Buscar_Usuario);

            if (wcscmp(Buscar_Usuario, L"No hay usuarios registrados") == 0) {
                MessageBox(hwnd, L"No hay usuarios registrados", L"Aviso", MB_ICONEXCLAMATION);
                regresar = true;
            }
            else if (wcscmp(Buscar_Usuario, L"NULL") == 0) {
                MessageBox(hwnd, L"No se seleccionó una opción", L"Aviso", MB_ICONEXCLAMATION);
                regresar = true;
            }
            else {
                while ((buscar1 != nullptr) && (wcscmp(Buscar_Usuario, buscar1->clavusuario) != 0)) {

                    buscar1 = buscar1->siguiente;
                }
            }
            regresar = false;
            EndDialog(hwnd, wParam);
            break;
        case IDC_BUTTON2:
            regresar = true;
            EndDialog(hwnd, wParam);
            break;

        }
        break;
    case WM_CLOSE:
        EndDialog(hwnd, wParam);

      
        break;

    }

    return FALSE;
}
BOOL CALLBACK Lista2(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    

    // size = size_arr;
    
    switch (uMsg)
    {
    case WM_CREATE:
    case WM_INITDIALOG:
        h_edit = GetDlgItem(hwnd, IDC_STATIC1);
        SetWindowText(h_edit, L"<Listado de pacientes>");

        h_edit = GetDlgItem(hwnd, IDC_STATIC2);
        SetWindowText(h_edit, L"Seleccione un paciente");

        
        h_listbox2 = GetDlgItem(hwnd, IDC_LIST1);
        
       
        listado_pacientes(lista2);
       
        break;


    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDC_BUTTON1:

            buscar2 = lista2;

            wcscpy_s(Buscar_Paciente, L"NULL");
            index = SendDlgItemMessage(hwnd, IDC_LIST1, LB_GETCURSEL, 0, 0);
            SendDlgItemMessage(hwnd, IDC_LIST1, LB_GETTEXT, index, (LPARAM)Buscar_Paciente);

            if (wcscmp(Buscar_Paciente, L"No hay pacientes registrados") == 0) {
                MessageBox(hwnd, L"No hay pacientes registrados", L"Aviso", MB_ICONEXCLAMATION);
                regresar = true;
            }
            else if (wcscmp(Buscar_Paciente, L"NULL") == 0) {
                MessageBox(hwnd, L"No se seleccionó una opción", L"Aviso", MB_ICONEXCLAMATION);
                regresar = true;
            }
            else {
                while ((buscar2 != nullptr) && (wcscmp(Buscar_Paciente, buscar2->CURP) != 0)) {

                    buscar2 = buscar2->siguiente;
                }
                regresar = false;
            }


            EndDialog(hwnd, wParam);
            break;
        case IDC_BUTTON2:
            regresar = true;
            EndDialog(hwnd, wParam);
            break;
        case IDC_BUTTON3:
            //QUICK = true;
            ArregloPQ(lista2);
            SendMessage(h_listbox2, LB_RESETCONTENT, 0, 0);
            for (int i = 0; i < size_arr; i++) {
                SendMessage(h_listbox2, LB_ADDSTRING, (WPARAM)0, (LPARAM)arregloQ[i]);
            }
            break;

        case IDC_BUTTON4:
            //QUICK = false;
            ArregloPH(lista2);
            SendMessage(h_listbox2, LB_RESETCONTENT, 0, 0);
            for (int i = 0; i < size_arr; i++) {
                buscar2 = lista2;
                while ((buscar2 != nullptr) && (arregloH[i] != buscar2->numpaciente)) {

                    buscar2 = buscar2->siguiente;
                }                
                SendMessage(h_listbox2, LB_ADDSTRING, (WPARAM)0, (LPARAM)buscar2->CURP);
            }
            break;
        }
        break;
    case WM_CLOSE:
        EndDialog(hwnd, wParam);

       
        break;

    }

    return FALSE;
}
BOOL CALLBACK Lista3(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg)
    {
    case WM_CREATE:
    case WM_INITDIALOG:
        h_edit = GetDlgItem(hwnd, IDC_STATIC1);
        SetWindowText(h_edit, L"<Listado de vacunas>");

        h_edit = GetDlgItem(hwnd, IDC_STATIC2);
        SetWindowText(h_edit, L"Seleccione una vacuna");

        h_listbox3 = GetDlgItem(hwnd, IDC_LIST1);
       

        listado_vacunas(lista3);

        break;


    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDC_BUTTON1:
            buscar3 = lista3;
            wcscpy_s(Buscar_Vacuna, L"NULL");
            index = SendDlgItemMessage(hwnd, IDC_LIST1, LB_GETCURSEL, 0, 0);
            SendDlgItemMessage(hwnd, IDC_LIST1, LB_GETTEXT, index, (LPARAM)Buscar_Vacuna);

            if (wcscmp(Buscar_Vacuna, L"No hay vacunas registradas") == 0) {
                MessageBox(hwnd, L"No hay vacunas registradas", L"Aviso", MB_ICONEXCLAMATION);
                regresar = true;
            }
            else if (wcscmp(Buscar_Vacuna, L"NULL") == 0) {
                MessageBox(hwnd, L"No se seleccionó una opción", L"Aviso", MB_ICONEXCLAMATION);
                regresar = true;
            }
            else {
                while ((buscar3 != nullptr) && (wcscmp(Buscar_Vacuna, buscar3->clavacuna) != 0)) {

                    buscar3 = buscar3->siguiente;
                }
                regresar = false;
            }
           
            EndDialog(hwnd, wParam);
            break;
        case IDC_BUTTON2:
            regresar = true;
            EndDialog(hwnd, wParam);
            break;

        }
        break;
    case WM_CLOSE:
        EndDialog(hwnd, wParam);

        
        break;

    }

    return FALSE;
}
BOOL CALLBACK Lista4(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    

    switch (uMsg)
    {
    case WM_CREATE:
    case WM_INITDIALOG:
        h_edit = GetDlgItem(hwnd, IDC_STATIC1);
        SetWindowText(h_edit, L"<Listado de carnes>");

        h_edit = GetDlgItem(hwnd, IDC_STATIC2);
        SetWindowText(h_edit, L"Seleccione un carne");

        /*h_edit = GetDlgItem(hwnd, IDC_STATIC3);
        SetWindowText(h_edit, L"Comercio: #");*/
        h_listbox4 = GetDlgItem(hwnd, IDC_LIST1);
       
        
        listado_carnes(lista4);

        break;


    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDC_BUTTON1:
            buscar4 = lista4;
            wcscpy_s(Buscar_Carne, L"NULL");
            index = SendDlgItemMessage(hwnd, IDC_LIST1, LB_GETCURSEL, 0, 0);
            SendDlgItemMessage(hwnd, IDC_LIST1, LB_GETTEXT, index, (LPARAM)Buscar_Carne);

            if (wcscmp(Buscar_Carne, L"No hay carnes registrados") == 0) {
                MessageBox(hwnd, L"No hay carnes registrados", L"Aviso", MB_ICONEXCLAMATION);
                regresar = true;
            }
            else if (wcscmp(Buscar_Carne, L"NULL") == 0) {
                MessageBox(hwnd, L"No se seleccionó una opción", L"Aviso", MB_ICONEXCLAMATION);
                regresar = true;
            }
            else {
              /*  while ((buscar4 != nullptr) && (wcscmp(Buscar_Carne, buscar4->ID) != 0)) {

                    buscar4 = buscar4->siguiente;
                }*/
                buscarlistaBinaria(lista4, NULL, Buscar_Carne);
                regresar = false;

            }
            EndDialog(hwnd, wParam);
            break;
        case IDC_BUTTON2:
            regresar=true;
            EndDialog(hwnd, wParam);
            break;

        }
        break;
    case WM_CLOSE:
        EndDialog(hwnd, wParam);

        EndDialog(ghDlg, wParam);
        break;

    }

    return FALSE;
}

//Usuarios------------------------------------------------------------------------------------------------------------------------
void agregar_usuario(usuarios*& lista1, wchar_t clavusu[50], wchar_t nomcom[50], wchar_t cont[50], wchar_t upaterno[50], wchar_t umaterno[20], wchar_t unombres[50], int numusu, bool newus) {

    usuarios* nuevo_usuario = new usuarios();
    usuarios* aux;
    wcscpy_s(nuevo_usuario->clavusuario, clavusu);
    wcscpy_s(nuevo_usuario->nombrecom, nomcom);
    wcscpy_s(nuevo_usuario->contraseña, cont);
    wcscpy_s(nuevo_usuario->paterno, upaterno);
    wcscpy_s(nuevo_usuario->materno, umaterno);
    wcscpy_s(nuevo_usuario->nombres, unombres);
    nuevo_usuario->numusuario = numusu;
    nuevo_usuario->NewUsuario = newus;
    nuevo_usuario->siguiente = nullptr;
    nuevo_usuario->anterior = nullptr;

    if (lista1 == nullptr) {  //si la lista esta vacia
        lista1 = nuevo_usuario;  //agregamos el primer elemento a la lista
        
    }
    else {
        aux = lista1;  //aux apunta al inicio de la lista

        while (aux->siguiente != nullptr) {  //recorrer la lista
            aux = aux->siguiente;  //avanzamos posiciones en la lista
        }
        aux->siguiente = nuevo_usuario;  //se agrega el nuevo nodo a la lista
        aux->siguiente->siguiente = nullptr;
        aux->siguiente->anterior = aux;
        aux = aux->siguiente;
    }
   
    k++;
}
void borrar_usuario(usuarios*& lista1, wchar_t Buscar_Usuario[50]) {

    usuarios* aux_borrar;
    usuarios* anterior = nullptr;
    aux_borrar = lista1;


    while ((aux_borrar != nullptr) && (wcscmp(Buscar_Usuario, aux_borrar->clavusuario) != 0)) {

        anterior = aux_borrar;
        aux_borrar = aux_borrar->siguiente;
    }

    if (aux_borrar == nullptr) { //El elemento no ha sido encontrado
         //cout << endl << ">Usuario no encontrada" << endl;
    }
    else if (anterior == nullptr) {  //El elemento a eliminar es el primero

        lista1 = lista1->siguiente;
        delete aux_borrar;
        //cout << endl << ">Usuario eliminado" << endl;
    }
    else {  //El elemento a eliminar no es el primero
        anterior->siguiente = aux_borrar->siguiente;
        delete aux_borrar;
        //cout << endl << ">Usuario eliminado" << endl;
    }
    k--;
}
BOOL CALLBACK RegistroUsuario(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

    switch (uMsg)
    {
    case WM_CREATE:
    case WM_INITDIALOG:
        h_edit = GetDlgItem(hwnd, IDC_STATIC1);
        SetWindowText(h_edit, L"Nueva clave");

        h_edit = GetDlgItem(hwnd, IDC_STATIC2);
        SetWindowText(h_edit, L"Ingrese nueva contraseña");

        wchar_t clavew[30];
        wchar_t j[10];
        wcscpy_s(clavew, L"USU");
        _itow_s(k + 1, j, 10, 10);
        wcscat_s(clavew, j);
        wcscat_s(clavew, L"D");

        g3 = GetDlgItem(hwnd, IDC_EDIT1);
        SetWindowText(g3, clavew);
        SendMessage(g3, EM_SETLIMITTEXT, 15, 0);
        g4 = GetDlgItem(hwnd, IDC_EDIT2);
        SetWindowText(g4, L"contraseña");
        SendMessage(g4, EM_SETLIMITTEXT, 10, 0);

        

        break;


    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDC_BUTTON1:
            GetWindowText(g3, (LPWSTR)clavusu, sizeof(clavusu));
          /*  wcscpy_s(PH, clavusu);
            VASIM(hwnd, PH);

            if (Cvalid == true) {
                validar1 = lista1;
                while ((validar1 != nullptr) && (wcscmp(clavusu, validar1->clavusuario) != 0)) {

                    validar1 = validar1->siguiente;

                }
                if (validar1 == nullptr) {*/
                    GetWindowText(g4, (LPWSTR)cont, sizeof(cont));

                    ContraValid(hwnd, cont);


                    if (Cvalid == true) {
                        //g5

                        wcscpy_s(nomcom, L"{PENDIENTE}");
                        wcscpy_s(unombres, L"{PENDIENTE}");
                        wcscpy_s(upaterno, L"{PENDIENTE}");
                        wcscpy_s(umaterno, L"{PENDIENTE}");

                        
                        newus = true;
                        
                        numusu = k + 1;
                        
                        agregar_usuario(lista1, clavusu, nomcom, cont, upaterno, umaterno, unombres, numusu, newus);
                       
                        MessageBox(hwnd, L"Usuario Registrado", L"Nuevo usuario", MB_ICONINFORMATION);
                        EndDialog(hwnd, wParam);
                    }
                    else {

                        MessageBox(hwnd, L"La contraseña tiene que tener un numero, un simbolo, y una letra sin espacios", L"Aviso", MB_ICONEXCLAMATION);
                    }
                /*}
                else {

                    MessageBox(hwnd, L"Ya hay un usuario con ese nombre", L"Aviso", MB_ICONEXCLAMATION);
                }
            }
            else {

                MessageBox(hwnd, L"El nombre de usuario solo puede llevar letras", L"Aviso", MB_ICONEXCLAMATION);
            }*/
            break;
        case IDC_BUTTON2:

            EndDialog(hwnd, wParam);
         
            break;
        }
        break;
    case WM_CLOSE:
        EndDialog(hwnd, wParam);

        break;



    }

    return FALSE;
}
BOOL CALLBACK ActualizarUA(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg)
    {
    case WM_CREATE:
    case WM_INITDIALOG:

      
        h_edit = GetDlgItem(hwnd, IDC_STATIC1);
        SetWindowText(h_edit, L"Ingrese apellido paterno");

        h_edit = GetDlgItem(hwnd, IDC_STATIC2);
        SetWindowText(h_edit, L"Ingrese apellido materno");

        h_edit = GetDlgItem(hwnd, IDC_STATIC3);
        SetWindowText(h_edit, L"Ingrese nombre completo");

        g5 = GetDlgItem(hwnd, IDC_EDIT1);
        SetWindowText(g5, actual->paterno);
        SendMessage(g5, EM_SETLIMITTEXT, 50, 0);

        g6 = GetDlgItem(hwnd, IDC_EDIT2);
        SetWindowText(g6, actual->materno);
        SendMessage(g6, EM_SETLIMITTEXT, 50, 0);

        g27 = GetDlgItem(hwnd, IDC_EDIT3);
        SetWindowText(g27, actual->nombres);
        SendMessage(g27, EM_SETLIMITTEXT, 50, 0);


        


        //wcscpy_s(img, actual->imagen);


        break;


    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDC_BUTTON1:
            GetWindowText(g5, (LPWSTR)upaterno, sizeof(upaterno));
            GetWindowText(g6, (LPWSTR)umaterno, sizeof(umaterno));
            GetWindowText(g27, (LPWSTR)unombres, sizeof(unombres));

            wcscpy_s(nomcom, unombres);
            wcscat_s(nomcom, L" ");
            wcscat_s(nomcom, upaterno);
            wcscat_s(nomcom, L" ");
            wcscat_s(nomcom, umaterno);
           
            wcscpy_s(PH, nomcom);
            VANUMSIM(hwnd, PH);
            if (Cvalid == true) {

               
                    wcscpy_s(actual->nombrecom, nomcom);
                    wcscpy_s(actual->nombres, unombres);
                    wcscpy_s(actual->paterno, upaterno);
                    wcscpy_s(actual->materno, umaterno);
                    
                    actual->NewUsuario = false;
                    regresar = false;
                    MessageBox(hwnd, L"Usuario Actualizado", L"Actualizar usuario", MB_ICONINFORMATION);
                    EndDialog(hwnd, wParam);
              
            }
            else {

                MessageBox(hwnd, L"El nombre solo puede llevar letras", L"Aviso", MB_ICONEXCLAMATION);
            }
            break;
        case IDC_BUTTON2:
            regresar = true;
            EndDialog(hwnd, wParam);
            break;
       /* case IDC_BUTTON3:

            AbrirImagen(hwnd);

            hBitmap1 = (HBITMAP)LoadImage(NULL, img, IMAGE_BITMAP, 100, 100, LR_LOADFROMFILE);
            SendDlgItemMessage(hwnd, IDC_PICTUREC, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap1);

            break;*/
        }
        break;
    case WM_CLOSE:
        DeleteObject((HBITMAP)hBitmap1);
        EndDialog(hwnd, wParam);

       
        break;



    }

    return FALSE;
}
BOOL CALLBACK NuevUsuario(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg)
    {
    case WM_CREATE:
    case WM_INITDIALOG:
        h_edit = GetDlgItem(hwnd, IDC_STATIC1);
        SetWindowText(h_edit, L"Ingrese apellido paterno");

        h_edit = GetDlgItem(hwnd, IDC_STATIC2);
        SetWindowText(h_edit, L"Ingrese apellido materno");

        h_edit = GetDlgItem(hwnd, IDC_STATIC3);
        SetWindowText(h_edit, L"Ingrese nombres");

        h_edit = GetDlgItem(hwnd, IDC_STATIC4);
        SetWindowText(h_edit, L"Ingrese contrasena");

        g8 = GetDlgItem(hwnd, IDC_EDIT1);
        SetWindowText(g8, L"{PENDIENTE}");
        SendMessage(g8, EM_SETLIMITTEXT, 50, 0);

        g9 = GetDlgItem(hwnd, IDC_EDIT2);
        SetWindowText(g9, L"{PENDIENTE}");
        SendMessage(g9, EM_SETLIMITTEXT, 50, 0);

        g10 = GetDlgItem(hwnd, IDC_EDIT3);
        SetWindowText(g10, L"{PENDIENTE}");
        SendMessage(g10, EM_SETLIMITTEXT, 50, 0);

        g28 = GetDlgItem(hwnd, IDC_EDIT4);
        SetWindowText(g28, L"{PENDIENTE}");
        SendMessage(g28, EM_SETLIMITTEXT, 10, 0);

        a35 = GetDlgItem(hwnd, IDC_STATIC5);
        wchar_t dummy[30];
        wchar_t j[10];
        wcscpy_s(dummy, L"USU");
        _itow_s(k + 1, j, 10, 10);
        wcscat_s(dummy, j);
        wcscat_s(dummy, L"D");
        SetWindowText(a35, dummy);

        break;


    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDC_BUTTON1:
            GetWindowText(g8, (LPWSTR)upaterno, sizeof(upaterno));
            GetWindowText(g9, (LPWSTR)umaterno, sizeof(umaterno));
            GetWindowText(g10, (LPWSTR)unombres, sizeof(unombres));

            wcscpy_s(nomcom, unombres);
            wcscat_s(nomcom, L" ");
            wcscat_s(nomcom, upaterno);
            wcscat_s(nomcom, L" ");
            wcscat_s(nomcom, umaterno);
            

            Cvalid = false;
            CV1 = 0, CV2 = 0;
            while ((nomcom[CV1] != L'\0') && (CV1 < 170)) {
                CV2 = 0;
                while (CV2 < 10) {
                    if (nomcom[CV1] == Validar1[CV2]) {

                        Cvalid = false;
                        CV1 = 170;
                        CV2 = 10;
                    }
                    else {
                        Cvalid = true;
                    }
                    CV2++;
                }
                CV1++;
            }
            if (Cvalid == true) {
                validar1 = lista1;
                while ((validar1 != nullptr) && (wcscmp(nomcom, validar1->nombrecom) != 0)) {

                    validar1 = validar1->siguiente;

                }
                if (validar1 == nullptr) {
                    GetWindowText(g28, (LPWSTR)cont, sizeof(cont));
                    ContraValid(hwnd, cont);



                    if (Cvalid == true) {
                        
                        
                        
                        
                        
                        wchar_t clavew[30];
                        wchar_t j[10];
                        wcscpy_s(clavusu, L"USU");
                        _itow_s(k + 1, j, 10, 10);
                        wcscat_s(clavusu, j);
                        wcscat_s(clavusu, L"D");
                      
                        numusu = k + 1;
                        
                        agregar_usuario(lista1, clavusu, nomcom, cont, upaterno, umaterno, unombres, numusu, newus);
                        MessageBox(hwnd, L"Usuario Registrado", L"Nuevo usuario", MB_ICONINFORMATION);
                        EndDialog(hwnd, wParam);
                    }
                    else {

                        MessageBox(hwnd, L"La contraseña tiene que tener un numero, un simbolo, y una letra sin espacios", L"Aviso", MB_ICONEXCLAMATION);
                    }
                }
                else {

                    MessageBox(hwnd, L"Ya hay un usuario con ese nombre", L"Aviso", MB_ICONEXCLAMATION);
                }
            }
            else {

                MessageBox(hwnd, L"El nombre de usuario no puede llevar numeros", L"Aviso", MB_ICONEXCLAMATION);
            }

            break;
        case IDC_BUTTON2:
            EndDialog(hwnd, wParam);
            break;
            return TRUE;
        }
        break;
    case WM_CLOSE:
        EndDialog(hwnd, wParam);

        
        break;

    }

    return FALSE;
}
BOOL CALLBACK ResConAct(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg)
    {
    case WM_CREATE:
    case WM_INITDIALOG:
        h_edit = GetDlgItem(hwnd, IDC_STATIC1);
        SetWindowText(h_edit, actual->contraseña);


        g11 = GetDlgItem(hwnd, IDC_EDIT1);
        SetWindowText(g11, L"nueva contraseña");
        SendMessage(g11, EM_SETLIMITTEXT, 10, 0);


        break;


    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDC_BUTTON1:
            GetWindowText(g11, (LPWSTR)cont, sizeof(cont));

            ContraValid(hwnd, cont);

            if (Cvalid == true) {
                wcscpy_s(actual->contraseña, cont);
                regresar = false;
                MessageBox(hwnd, L"Contraseña Actualizada", L"Actualizar contraseña", MB_ICONINFORMATION);
                EndDialog(hwnd, wParam);
            }
            else {

                MessageBox(hwnd, L"La contraseña tiene que tener un numero, un simbolo, y una letra sin espacios", L"Aviso", MB_ICONEXCLAMATION);
            }
            break;
        case IDC_BUTTON2:
            regresar = true;
            EndDialog(hwnd, wParam);

            break;
        }
        break;
    case WM_CLOSE:
        EndDialog(hwnd, wParam);

       
        break;

    }

    return FALSE;
}
BOOL CALLBACK ResConAct2(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg)
    {
    case WM_CREATE:
    case WM_INITDIALOG:
        h_edit = GetDlgItem(hwnd, IDC_STATIC1);
        SetWindowText(h_edit, buscar1->contraseña);


        g23 = GetDlgItem(hwnd, IDC_EDIT1);
        SetWindowText(g23, L"nueva contraseña");
        SendMessage(g23, EM_SETLIMITTEXT, 10, 0);


        break;


    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDC_BUTTON1:
            GetWindowText(g23, (LPWSTR)cont, sizeof(cont));
            ContraValid(hwnd, cont);
            if (Cvalid == true) {
                wcscpy_s(buscar1->contraseña, cont);
                MessageBox(hwnd, L"Contraseña Actualizada", L"Actualizar contraseña", MB_ICONINFORMATION);
                regresar = false;
                EndDialog(hwnd, wParam);
            }
            else {

                MessageBox(hwnd, L"La contraseña tiene que tener un numero, un simbolo, y una letra sin espacios", L"Aviso", MB_ICONEXCLAMATION);
            }
            break;
        case IDC_BUTTON2:
            regresar = true;
            EndDialog(hwnd, wParam);

            break;
        }
        break;
    case WM_CLOSE:
        EndDialog(hwnd, wParam);

       
        break;

    }

    return FALSE;
}
BOOL CALLBACK Actusu(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_CREATE:
    case WM_INITDIALOG:

       /* hPictureControl = GetDlgItem(hwnd, IDC_PICTUREC);
        hBitmap3 = (HBITMAP)LoadImage(NULL, buscar1->imagen, IMAGE_BITMAP, 100, 100, LR_LOADFROMFILE);
        SendDlgItemMessage(hwnd, IDC_PICTUREC, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap3);*/

        h_edit = GetDlgItem(hwnd, IDC_BUTTON1);
        SetWindowText(h_edit, L"Actualizar usuario");
        h_edit = GetDlgItem(hwnd, IDC_BUTTON2);
        SetWindowText(h_edit, L"Eliminar usuario");
        a4 = GetDlgItem(hwnd, IDC_STATIC0);
        SetWindowText(a4, buscar1->clavusuario);
        a5 = GetDlgItem(hwnd, IDC_STATIC2);
        SetWindowText(a5, buscar1->paterno);
        a6 = GetDlgItem(hwnd, IDC_STATIC3);
        SetWindowText(a6, buscar1->materno);
        a7 = GetDlgItem(hwnd, IDC_STATIC4);
        SetWindowText(a7, buscar1->nombres);
       /* a8 = GetDlgItem(hwnd, IDC_STATIC5);

        if (buscar1->Admin == true) {
            SetWindowText(a8, L"Admin: Si");
        }
        else {
            SetWindowText(a8, L"Admin: No");
        }*/

        break;
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case ID_ARCHIVO_GUARDAR:
            MessageBox(hwnd, L"mensaje", L"titulo", MB_ICONEXCLAMATION);
            break;
        case ID_ARCHIVO_GUARDARCOMO:
            MessageBox(hwnd, L"mensaje", L"titulo", MB_ICONEXCLAMATION);
            break;
        case IDC_BUTTON1:
            
            
            
            DialogBox(NULL, MAKEINTRESOURCE(IDD_ACTUS), hwnd, (DLGPROC)ActusuB1);
            

            SetWindowText(a4, buscar1->clavusuario);

            SetWindowText(a5, buscar1->paterno);

            SetWindowText(a6, buscar1->materno);

            SetWindowText(a7, buscar1->nombres);

            /*if (buscar1->Admin == true) {
                SetWindowText(a8, L"Admin: Si");
            }
            else {
                SetWindowText(a8, L"Admin: No");
            }
            hBitmap3 = (HBITMAP)LoadImage(NULL, buscar1->imagen, IMAGE_BITMAP, 100, 100, LR_LOADFROMFILE);
            SendDlgItemMessage(hwnd, IDC_PICTUREC, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap3);*/
            break;
        case IDC_BUTTON2:
            
                DialogBox(NULL, MAKEINTRESOURCE(IDD_CONFIRMAR), hwnd, (DLGPROC)Confirmar);
                if (confirmar == true) {
                    if (wcscmp(actual->clavusuario, Buscar_Usuario) == 0) {
                        MessageBox(hwnd, L"No puede eliminar el usuario actual", L"Aviso", MB_ICONSTOP);
                    }
                    else {
                        borrar_usuario(lista1, Buscar_Usuario);
                        MessageBox(hwnd, L"Usuario Eliminado", L"Eliminar usuario", MB_ICONINFORMATION);
                        EndDialog(hwnd, wParam);
                    }
                }
           

            break;
        case IDC_BUTTON5:
            EndDialog(hwnd, wParam);


            break;
        }
        break;
    case WM_CLOSE:
        
        DestroyWindow(hwnd);
        DestroyMenu(hMenu);
       
        break;
    }
    return FALSE;
}
BOOL CALLBACK ActusuB1(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_CREATE:
    case WM_INITDIALOG:

       /* hPictureControl = GetDlgItem(hwnd, IDC_PICTUREC);
        hBitmap4 = (HBITMAP)LoadImage(NULL, buscar1->imagen, IMAGE_BITMAP, 100, 100, LR_LOADFROMFILE);
        SendDlgItemMessage(hwnd, IDC_PICTUREC, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap4);*/


        h_edit = GetDlgItem(hwnd, IDC_STATIC1);
        SetWindowText(h_edit, L"Ingrese nuevo apellido paterno");

        h_edit = GetDlgItem(hwnd, IDC_STATIC2);
        SetWindowText(h_edit, L"Ingrese nuevo apellido maternoo");

        h_edit = GetDlgItem(hwnd, IDC_STATIC3);
        SetWindowText(h_edit, L"Ingrese nuevos nombres");

       /* h_edit = GetDlgItem(hwnd, IDC_CHECK1);
        SetWindowText(h_edit, L"Administrador");
        if (buscar1->Admin) {
            SendDlgItemMessage(hwnd, IDC_CHECK1, BM_SETCHECK, (WPARAM)BST_CHECKED, 0);
        }
        else {
            SendDlgItemMessage(hwnd, IDC_CHECK1, BM_SETCHECK, (WPARAM)BST_UNCHECKED, 0);
        }
        h_edit = GetDlgItem(hwnd, IDC_STATIC4);
        SetWindowText(h_edit, L"Ingrese nueva foto de usuario");*/

        g12 = GetDlgItem(hwnd, IDC_EDIT1);
        SetWindowText(g12, buscar1->paterno);
        SendMessage(g12, EM_SETLIMITTEXT, 15, 0);

        g13 = GetDlgItem(hwnd, IDC_EDIT2);
        SetWindowText(g13, buscar1->materno);
        SendMessage(g13, EM_SETLIMITTEXT, 50, 0);

        g14 = GetDlgItem(hwnd, IDC_EDIT3);
        SetWindowText(g14, buscar1->nombres);
        SendMessage(g14, EM_SETLIMITTEXT, 50, 0);

        


        break;
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case ID_ARCHIVO_GUARDAR:
            MessageBox(hwnd, L"mensaje", L"titulo", MB_ICONEXCLAMATION);
            break;
        case ID_ARCHIVO_GUARDARCOMO:
            MessageBox(hwnd, L"mensaje", L"titulo", MB_ICONEXCLAMATION);
            break;
        case IDC_BUTTON1:

            GetWindowText(g12, (LPWSTR)upaterno, sizeof(upaterno));
            GetWindowText(g13, (LPWSTR)umaterno, sizeof(umaterno));
            GetWindowText(g14, (LPWSTR)unombres, sizeof(unombres));

            wcscpy_s(nomcom, unombres);
            wcscat_s(nomcom, L" ");
            wcscat_s(nomcom, upaterno);
            wcscat_s(nomcom, L" ");
            wcscat_s(nomcom, umaterno);

            wcscpy_s(PH, nomcom);
            VANUMSIM(hwnd, PH);
            if (Cvalid == true) {

                validar1 = lista1;
                while ((validar1 != nullptr) && ((wcscmp(nomcom, validar1->nombrecom) != 0) || (wcscmp(nomcom, buscar1->nombrecom) == 0))) {

                    validar1 = validar1->siguiente;

                }
                if (validar1 == nullptr) {
                   
                            wcscpy_s(buscar1->nombrecom, nomcom);
                            wcscpy_s(buscar1->paterno, upaterno);
                            wcscpy_s(buscar1->materno, umaterno);
                            wcscpy_s(buscar1->nombres, unombres);
                            buscar1->NewUsuario = false;
                            MessageBox(hwnd, L"Usuario Actualizado", L"Actualizar usuario", MB_ICONINFORMATION);
                            EndDialog(hwnd, wParam);
                       
                }
                else {
                    MessageBox(hwnd, L"Ya hay un usuario con ese nombre", L"Aviso", MB_ICONEXCLAMATION);
                }
            }
            else {

                MessageBox(hwnd, L"El nombre de usuario no puede llevar numeros", L"Aviso", MB_ICONEXCLAMATION);
            }
            break;
        case IDC_BUTTON2:

            EndDialog(hwnd, wParam);
            

            break;
        case IDC_BUTTON3:
            AbrirImagen(hwnd);

            hBitmap4 = (HBITMAP)LoadImage(NULL, img, IMAGE_BITMAP, 100, 100, LR_LOADFROMFILE);
            SendDlgItemMessage(hwnd, IDC_PICTUREC, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap4);

            break;
        case IDC_BUTTON5:
            EndDialog(hwnd, wParam);


            break;
        }
        break;
    case WM_CLOSE:
        
        DestroyWindow(hwnd);
        DestroyMenu(hMenu);
      
        break;
    }
    return FALSE;
}
BOOL CALLBACK ResCon(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg)
    {
    case WM_CREATE:
    case WM_INITDIALOG:
        /*h_edit = GetDlgItem(hwnd, IDC_STATIC1);
        SetWindowText(h_edit, L"<Opciones de clientes>");*/
        h_edit = GetDlgItem(hwnd, IDC_STATIC4);
        SetWindowText(h_edit, L"Seleccione una opción");
        h_edit = GetDlgItem(hwnd, IDC_BUTTON1);
        SetWindowText(h_edit, L"Restablecer mi contrasena");
        h_edit = GetDlgItem(hwnd, IDC_BUTTON2);
        SetWindowText(h_edit, L"Restablecer otro usuario");
        break;


    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case ID_ARCHIVO_GUARDAR:
            MessageBox(hwnd, L"mensaje", L"titulo", MB_ICONEXCLAMATION);
            break;
        case ID_ARCHIVO_GUARDARCOMO:
            MessageBox(hwnd, L"mensaje", L"titulo", MB_ICONEXCLAMATION);
            break;
        case ID_SALIR_SALIRSINGUARDAR:
            DestroyWindow(hwnd);
            DestroyMenu(hMenu);
            DestroyWindow(ghDlg);
            break;
        case IDC_BUTTON1:

            DialogBox(NULL, MAKEINTRESOURCE(IDD_RESTABLECER), hwnd, (DLGPROC)ResConAct);

            break;
        case IDC_BUTTON2:
           
                DialogBox(NULL, MAKEINTRESOURCE(IDD_LISTA), hwnd, (DLGPROC)Lista1);
               
                if (regresar == false) {
                    DialogBox(NULL, MAKEINTRESOURCE(IDD_RESTABLECER), hwnd, (DLGPROC)ResConAct2);
                }
           
            break;

        case IDC_BUTTON5:
            EndDialog(hwnd, wParam);


        }
        break;
    case WM_CLOSE:

        DestroyWindow(hwnd);
        DestroyMenu(hMenu);
      
        break;

    }

    return FALSE;
}

//Pacientes------------------------------------------------------------------------------------------------------------------------
void agregar_paciente(pacientes*& lista2, wchar_t pater[50], wchar_t mater[50], wchar_t nombs[50], wchar_t nomc[170], wchar_t curp[20], wchar_t rfc[20], wchar_t nacim[30], wchar_t call[50], wchar_t col[50],
    wchar_t cid[50], wchar_t edo[50], wchar_t edociv[50], wchar_t tel[11], wchar_t ddi[100], wchar_t sex[10], wchar_t go[50], wchar_t pr[50], int numpac) {

    pacientes* nuevo_paciente = new pacientes();
    pacientes* aux;

    wcscpy_s(nuevo_paciente->paterno, pater);    wcscpy_s(nuevo_paciente->materno, mater);
    wcscpy_s(nuevo_paciente->nombres, nombs);    wcscpy_s(nuevo_paciente->nombrecom, nomc);
    wcscpy_s(nuevo_paciente->CURP, curp);    wcscpy_s(nuevo_paciente->RFC, rfc);
    wcscpy_s(nuevo_paciente->nacimiento, nacim);    wcscpy_s(nuevo_paciente->calle, call);
    wcscpy_s(nuevo_paciente->colonia, col);    wcscpy_s(nuevo_paciente->ciudad, cid);
    wcscpy_s(nuevo_paciente->estado, edo);    wcscpy_s(nuevo_paciente->edocivil, edociv);
    wcscpy_s(nuevo_paciente->telefono, tel);       wcscpy_s(nuevo_paciente->DdI, ddi);
    wcscpy_s(nuevo_paciente->sexo, sex);    wcscpy_s(nuevo_paciente->GO, go);
    wcscpy_s(nuevo_paciente->PR, pr);

    nuevo_paciente->numpaciente = numpac;
    nuevo_paciente->siguiente = nullptr;
    nuevo_paciente->anterior = nullptr;

   
    if (lista2 == nullptr) {  //si la lista esta vacia
        lista2 = nuevo_paciente;  //agregamos el primer elemento a la lista
        m++;
    }
    else {
        aux = lista2;  //aux apunta al inicio de la lista

        while (aux->siguiente != nullptr) {  //recorrer la lista
            aux = aux->siguiente;  //avanzamos posiciones en la lista
        }
        aux->siguiente = nuevo_paciente;  //se agrega el nuevo nodo a la lista
        aux->siguiente->siguiente = nullptr;
        aux->siguiente->anterior = aux;
        aux = aux->siguiente;
        m++;
    }
 
}
void borrar_paciente(pacientes*& lista2, wchar_t Buscar_Paciente[50]) {

    pacientes* aux_borrar;
    pacientes* anterior = nullptr;
    aux_borrar = lista2;

    while ((aux_borrar != nullptr) && (wcscmp(Buscar_Paciente, aux_borrar->CURP) != 0)) { //recorrer la lista

        anterior = aux_borrar;
        aux_borrar = aux_borrar->siguiente;
    }

    if (anterior == nullptr) {  //El elemento a eliminar es el primero

        lista2 = lista2->siguiente;
        delete aux_borrar;
        m--;
    }
    else {  //El elemento a eliminar no es el primero
        anterior->siguiente = aux_borrar->siguiente;
        delete aux_borrar;
        m--;
    }
    
   
}
BOOL CALLBACK NuevPaciente(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg)
    {
    case WM_CREATE:
    case WM_INITDIALOG:
        hPictureControl = GetDlgItem(hwnd, IDC_PICTUREC);
        hBitmap1 = (HBITMAP)LoadImage(NULL, buscar2->DdI, IMAGE_BITMAP, 100, 100, LR_LOADFROMFILE);
        SendDlgItemMessage(hwnd, IDC_PICTUREC, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap1);



        g24 = GetDlgItem(hwnd, IDC_DATETIMEPICKER1);
        GetWindowText(g24, (LPWSTR)nacim, sizeof(nacim));
        h_edit = GetDlgItem(hwnd, IDC_STATIC6);
        SetWindowText(h_edit, nacim);

        SendDlgItemMessage(hwnd, IDC_RADIO1, BM_SETCHECK, (WPARAM)BST_CHECKED, 0);
        SendDlgItemMessage(hwnd, IDC_RADIO3, BM_SETCHECK, (WPARAM)BST_CHECKED, 0);

        if (wcscmp(buscar2->sexo, L"M") == 0) {
            SendDlgItemMessage(hwnd, IDC_RADIO1, BM_SETCHECK, (WPARAM)BST_CHECKED, 0);
            SendDlgItemMessage(hwnd, IDC_RADIO2, BM_SETCHECK, (WPARAM)BST_UNCHECKED, 0);
        }
        if (wcscmp(buscar2->sexo, L"F") == 0){
            SendDlgItemMessage(hwnd, IDC_RADIO1, BM_SETCHECK, (WPARAM)BST_UNCHECKED, 0);
            SendDlgItemMessage(hwnd, IDC_RADIO2, BM_SETCHECK, (WPARAM)BST_CHECKED, 0);
        }
        if (wcscmp(buscar2->edocivil, L"Soltero") == 0) {
            SendDlgItemMessage(hwnd, IDC_RADIO3, BM_SETCHECK, (WPARAM)BST_CHECKED, 0);
            SendDlgItemMessage(hwnd, IDC_RADIO4, BM_SETCHECK, (WPARAM)BST_UNCHECKED, 0);
        }
        if (wcscmp(buscar2->edocivil, L"Casado") == 0) {
            SendDlgItemMessage(hwnd, IDC_RADIO3, BM_SETCHECK, (WPARAM)BST_UNCHECKED, 0);
            SendDlgItemMessage(hwnd, IDC_RADIO4, BM_SETCHECK, (WPARAM)BST_CHECKED, 0);
        }

        if (nuevo == true) {
            g15 = GetDlgItem(hwnd, IDC_EDIT1);
            SetWindowText(g15, L"{PENDIENTE}");
            g16 = GetDlgItem(hwnd, IDC_EDIT2);
            SetWindowText(g16, L"{PENDIENTE}");
            g17 = GetDlgItem(hwnd, IDC_EDIT3);
            SetWindowText(g17, L"{PENDIENTE}");
            g18 = GetDlgItem(hwnd, IDC_EDIT4);
            SetWindowText(g18, L"{PENDIENTE}");
            g28 = GetDlgItem(hwnd, IDC_EDIT5);
            SetWindowText(g28, L"{PENDIENTE}");
            g29 = GetDlgItem(hwnd, IDC_EDIT6);
            SetWindowText(g29, L"{PENDIENTE}");
            g30 = GetDlgItem(hwnd, IDC_EDIT7);
            SetWindowText(g30, L"{PENDIENTE}");
            g31 = GetDlgItem(hwnd, IDC_EDIT8);
            SetWindowText(g31, L"{PENDIENTE}");
            g32 = GetDlgItem(hwnd, IDC_EDIT9);
            SetWindowText(g32, L"{PENDIENTE}");
            g33 = GetDlgItem(hwnd, IDC_EDIT10);
            SetWindowText(g33, L"{PENDIENTE}");
            g34 = GetDlgItem(hwnd, IDC_EDIT11);
            SetWindowText(g34, L"{PENDIENTE}");
            g35 = GetDlgItem(hwnd, IDC_EDIT12);
            SetWindowText(g35, L"{PENDIENTE}");


        }
        else {
            g15 = GetDlgItem(hwnd, IDC_EDIT1);
            SetWindowText(g15, buscar2->paterno);
            g16 = GetDlgItem(hwnd, IDC_EDIT2);
            SetWindowText(g16, buscar2->materno);
            g17 = GetDlgItem(hwnd, IDC_EDIT3);
            SetWindowText(g17, buscar2->nombres);
            g18 = GetDlgItem(hwnd, IDC_EDIT4);
            SetWindowText(g18, buscar2->CURP);
            g28 = GetDlgItem(hwnd, IDC_EDIT5);
            SetWindowText(g28, buscar2->RFC);
            g29 = GetDlgItem(hwnd, IDC_EDIT6);
            SetWindowText(g29, buscar2->calle);
            g30 = GetDlgItem(hwnd, IDC_EDIT7);
            SetWindowText(g30, buscar2->colonia);
            g31 = GetDlgItem(hwnd, IDC_EDIT8);
            SetWindowText(g31, buscar2->ciudad);
            g32 = GetDlgItem(hwnd, IDC_EDIT9);
            SetWindowText(g32, buscar2->estado);
            g33 = GetDlgItem(hwnd, IDC_EDIT10);
            SetWindowText(g33, buscar2->telefono);
            g34 = GetDlgItem(hwnd, IDC_EDIT11);
            SetWindowText(g34, buscar2->GO);
            g35 = GetDlgItem(hwnd, IDC_EDIT12);
            SetWindowText(g35, buscar2->PR);
        }
        SendMessage(g15, EM_SETLIMITTEXT, 50, 0);
        SendMessage(g16, EM_SETLIMITTEXT, 50, 0);
        SendMessage(g17, EM_SETLIMITTEXT, 50, 0);
        SendMessage(g18, EM_SETLIMITTEXT, 18, 0);
        SendMessage(g28, EM_SETLIMITTEXT, 13, 0);
        SendMessage(g29, EM_SETLIMITTEXT, 50, 0);
        SendMessage(g30, EM_SETLIMITTEXT, 50, 0);
        SendMessage(g31, EM_SETLIMITTEXT, 50, 0);
        SendMessage(g32, EM_SETLIMITTEXT, 50, 0);
        SendMessage(g33, EM_SETLIMITTEXT, 10, 0);
        SendMessage(g34, EM_SETLIMITTEXT, 50, 0);
        SendMessage(g35, EM_SETLIMITTEXT, 50, 0);

        break;

    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
            /*case ID_ARCHIVO_GUARDAR:
                MessageBox(hwnd, L"mensaje", L"titulo", MB_ICONEXCLAMATION);
                break;
            case ID_ARCHIVO_GUARDARCOMO:
                MessageBox(hwnd, L"mensaje", L"ttulo", MB_ICONEXCLAMATION);
                break;*/
        case IDC_BUTTON1:
            if (nuevo == true) {
                GetWindowText(g15, (LPWSTR)pater, sizeof(pater));
                GetWindowText(g16, (LPWSTR)mater, sizeof(mater));
                GetWindowText(g17, (LPWSTR)nombs, sizeof(nombs));

                wcscpy_s(nomc, pater);
                wcscat_s(nomc, L" ");
                wcscat_s(nomc, mater);
                wcscat_s(nomc, L", ");
                wcscat_s(nomc, nombs);
                
                
                wcscpy_s(PH, nomc);
                VANUMSIM(hwnd, PH);

                if (Cvalid == true) {
                    validar2 = lista2;
                    while ((validar2 != nullptr) && (wcscmp(nomc, validar2->nombrecom) != 0)) {

                        validar2 = validar2->siguiente;

                    }
                    if (validar2 == nullptr) {
                        GetWindowText(g18, (LPWSTR)curp, sizeof(curp));
                        wcscpy_s(PH, curp);
                        VASIM(hwnd, PH);
                        
                        if (Cvalid == true) {
                            CV1 = 0;
                            while (CV1 < 18) {

                                if ((curp[CV1] == L'\0') || (curp[CV1] == L' ')) {
                                    Cvalid = false;
                                    CV1 = 18;

                                }
                                else {
                                    Cvalid = true;
                                }

                                CV1++;
                            }
                        }
                        if (Cvalid == true) { 
                            validar2 = lista2;
                            while ((validar2 != nullptr) && (wcscmp(curp, validar2->CURP) != 0)) {

                                validar2 = validar2->siguiente;

                            }
                            if (validar2 == nullptr) {
                                GetWindowText(g28, (LPWSTR)rfc, sizeof(rfc));

                                wcscpy_s(PH, rfc);
                                VASIM(hwnd, PH);
                               /* if (Cvalid == true) {
                                    CV1 = 0;
                                    while (CV1 < 13) {

                                        if ((rfc[CV1] == L'\0') || (rfc[CV1] == L' ')) {
                                            Cvalid = false;
                                            CV1 = 13;

                                        }
                                        else {
                                            Cvalid = true;
                                        }

                                        CV1++;
                                    }
                                }*/
                                if (Cvalid == true) {
                                    while ((validar2 != nullptr) && (wcscmp(rfc, validar2->RFC) != 0)) {

                                        validar2 = validar2->siguiente;

                                    }
                                    if (validar2 == nullptr) {
                                        GetWindowText(g29, (LPWSTR)call, sizeof(call));
                                        GetWindowText(g30, (LPWSTR)col, sizeof(col));
                                        GetWindowText(g31, (LPWSTR)cid, sizeof(cid));
                                        GetWindowText(g32, (LPWSTR)edo, sizeof(edo));

                                        wcscpy_s(direccion, call);
                                        wcscat_s(direccion, col);
                                        wcscat_s(direccion, cid);
                                        wcscat_s(direccion, edo);

                                        wcscpy_s(PH, direccion);
                                        VASIM(hwnd, PH);
                                        if (Cvalid == true) {


                                            GetWindowText(g33, (LPWSTR)tel, sizeof(tel));
                                            Cvalid = false;
                                            CV1 = 0;
                                            while (CV1 < 10) {

                                                if (tel[CV1] == L'\0') {
                                                    Cvalid = false;
                                                    CV1 = 10;

                                                }
                                                else {
                                                    Cvalid = true;
                                                }

                                                CV1++;
                                            }
                                            if (Cvalid == true) {
                                                GetWindowText(g34, (LPWSTR)go, sizeof(go));
                                                GetWindowText(g35, (LPWSTR)pr, sizeof(pr));
                                                wcscpy_s(gopro, go);
                                                wcscat_s(gopro, pr);

                                                wcscpy_s(PH, gopro);
                                                VANUMSIM(hwnd, PH);
                                                if (Cvalid == true) {


                                                    //numpac = m + 1;
                                                    numpac = 200;

                                                    if (IsDlgButtonChecked(hwnd, IDC_RADIO1) == BST_CHECKED) {
                                                        wcscpy_s(sex, L"M");
                                                    }
                                                    else if (IsDlgButtonChecked(hwnd, IDC_RADIO2) == BST_CHECKED) {
                                                        wcscpy_s(sex, L"F");
                                                    }

                                                    if (IsDlgButtonChecked(hwnd, IDC_RADIO3) == BST_CHECKED) {
                                                        wcscpy_s(edociv, L"Soltero");
                                                    }
                                                    else if (IsDlgButtonChecked(hwnd, IDC_RADIO4) == BST_CHECKED) {
                                                        wcscpy_s(edociv, L"Casado");
                                                    }
                                                    wcscpy_s(ddi, img);
                                                    GetWindowText(g24, (LPWSTR)nacim, sizeof(nacim));
                                                    agregar_paciente(lista2, pater, mater, nombs, nomc, curp, rfc, nacim, call, col, cid, edo, edociv, tel, ddi, sex, go, pr, numpac);
                                                    MessageBox(hwnd, L"Paciente Registrado", L"Registrar paciente", MB_ICONINFORMATION);
                                                    EndDialog(hwnd, wParam);
                                                }
                                                else {
                                                    MessageBox(hwnd, L"El grupo ocupacional y/o perfil de riesgo no puede contener ", L"Aviso", MB_ICONEXCLAMATION);
                                                }
                                            }
                                            else {

                                                MessageBox(hwnd, L"Ingrese un teléfono válido", L"Aviso", MB_ICONEXCLAMATION);
                                            }

                                        }
                                        else {
                                            MessageBox(hwnd, L"La dirrección del paciente no puede contener simbolos", L"Aviso", MB_ICONEXCLAMATION);
                                        }
                                    }
                                    else {
                                        MessageBox(hwnd, L"Ya hay un paciente con ese RFC", L"Aviso", MB_ICONEXCLAMATION);
                                    }
                                }
                                else {
                                    MessageBox(hwnd, L"El RFC no puede contener simbolos o espacios", L"Aviso", MB_ICONEXCLAMATION);
                                }
                            }
                            else {
                                MessageBox(hwnd, L"Ya hay un paciente con ese CURP", L"Aviso", MB_ICONEXCLAMATION);
                            }
                        }
                        else {
                            MessageBox(hwnd, L"El CURP no puede contener simbolos o espacios", L"Aviso", MB_ICONEXCLAMATION);
                        }
                    }
                    else {
                        MessageBox(hwnd, L"Ya hay un paciente registrado con ese nombre", L"Aviso", MB_ICONEXCLAMATION);
                    }
                }
                else {
                    MessageBox(hwnd, L"El nombre solo puede contener letras", L"Aviso", MB_ICONEXCLAMATION);
                }
            }
            else {
                GetWindowText(g15, (LPWSTR)pater, sizeof(pater));
                GetWindowText(g16, (LPWSTR)mater, sizeof(mater));
                GetWindowText(g17, (LPWSTR)nombs, sizeof(nombs));

                wcscpy_s(nomc, pater);
                wcscat_s(nomc, L" ");
                wcscat_s(nomc, mater);
                wcscat_s(nomc, L", ");
                wcscat_s(nomc, nombs);


                wcscpy_s(PH, nomc);
                VANUMSIM(hwnd, PH);

                if (Cvalid == true) {
                    validar2 = lista2;
                    while ((validar2 != nullptr) && ((wcscmp(nomc, validar2->nombrecom) != 0) || (wcscmp(nomc, buscar2->nombrecom) == 0))) {

                        validar2 = validar2->siguiente;

                    }
                    if (validar2 == nullptr) {
                        GetWindowText(g18, (LPWSTR)curp, sizeof(curp));
                        wcscpy_s(PH, curp);
                        VASIM(hwnd, PH);
                        if (Cvalid == true) {
                            CV1 = 0;
                            while (CV1 < 18) {

                                if ((curp[CV1] == L'\0') || (curp[CV1] == L' ')) {
                                    Cvalid = false;
                                    CV1 = 18;

                                }
                                else {
                                    Cvalid = true;
                                }

                                CV1++;
                            }
                        }
                        if (Cvalid == true) {
                            validar2 = lista2;
                            
                            while ((validar2 != nullptr) && ((wcscmp(curp, validar2->CURP) != 0) || (wcscmp(curp, buscar2->CURP) == 0))) {

                                validar2 = validar2->siguiente;

                            }
                            if (validar2 == nullptr) {
                                GetWindowText(g28, (LPWSTR)rfc, sizeof(rfc));

                                wcscpy_s(PH, rfc);
                                VASIM(hwnd, PH);
                               /* if (Cvalid == true) {
                                    CV1 = 0;
                                    while (CV1 < 13) {

                                        if ((rfc[CV1] == L'\0') || (rfc[CV1] == L' ')) {
                                            Cvalid = false;
                                            CV1 = 13;

                                        }
                                        else {
                                            Cvalid = true;
                                        }

                                        CV1++;
                                    }
                                }*/
                                if (Cvalid == true) {
                                    while ((validar2 != nullptr) && ((wcscmp(rfc, validar2->RFC) != 0) || (wcscmp(rfc, buscar2->RFC) == 0))) {

                                        validar2 = validar2->siguiente;

                                    }
                                    if (validar2 == nullptr) {
                                        GetWindowText(g29, (LPWSTR)call, sizeof(call));
                                        GetWindowText(g30, (LPWSTR)col, sizeof(col));
                                        GetWindowText(g31, (LPWSTR)cid, sizeof(cid));
                                        GetWindowText(g32, (LPWSTR)edo, sizeof(edo));

                                        wcscpy_s(direccion, call);
                                        wcscat_s(direccion, col);
                                        wcscat_s(direccion, cid);
                                        wcscat_s(direccion, edo);

                                        wcscpy_s(PH, nomc);
                                        VASIM(hwnd, PH);
                                        if (Cvalid == true) {


                                            GetWindowText(g33, (LPWSTR)tel, sizeof(tel));
                                            Cvalid = false;
                                            CV1 = 0;
                                            while (CV1 < 10) {

                                                if (tel[CV1] == L'\0') {
                                                    Cvalid = false;
                                                    CV1 = 10;

                                                }
                                                else {
                                                    Cvalid = true;
                                                }

                                                CV1++;
                                            }
                                            if (Cvalid == true) {
                                                GetWindowText(g34, (LPWSTR)go, sizeof(go));
                                                GetWindowText(g35, (LPWSTR)pr, sizeof(pr));
                                                wcscpy_s(gopro, go);
                                                wcscat_s(gopro, pr);

                                                wcscpy_s(PH, gopro);
                                                VANUMSIM(hwnd, PH);
                                                if (Cvalid == true) {


                                                    numpac = buscar2->numpaciente;


                                                    if (IsDlgButtonChecked(hwnd, IDC_RADIO1) == BST_CHECKED) {
                                                        wcscpy_s(sex, L"M");
                                                    }
                                                    else if (IsDlgButtonChecked(hwnd, IDC_RADIO2) == BST_CHECKED) {
                                                        wcscpy_s(sex, L"F");
                                                    }

                                                    if (IsDlgButtonChecked(hwnd, IDC_RADIO3) == BST_CHECKED) {
                                                        wcscpy_s(edociv, L"Soltero");
                                                    }
                                                    else if (IsDlgButtonChecked(hwnd, IDC_RADIO4) == BST_CHECKED) {
                                                        wcscpy_s(edociv, L"Casado");
                                                    }
                                                    wcscpy_s(ddi, img);
                                                    GetWindowText(g24, (LPWSTR)nacim, sizeof(nacim));



                                                    wcscpy_s(buscar2->paterno, pater);
                                                    wcscpy_s(buscar2->materno, mater);
                                                    wcscpy_s(buscar2->nombres, nombs);
                                                    wcscpy_s(buscar2->nombrecom, nomc);
                                                    wcscpy_s(buscar2->CURP, curp);
                                                    wcscpy_s(buscar2->RFC, rfc);
                                                    wcscpy_s(buscar2->nacimiento, nacim);
                                                    wcscpy_s(buscar2->calle, call);
                                                    wcscpy_s(buscar2->colonia, col);
                                                    wcscpy_s(buscar2->ciudad, cid);
                                                    wcscpy_s(buscar2->estado, edo);
                                                    wcscpy_s(buscar2->edocivil, edociv);
                                                    wcscpy_s(buscar2->telefono, tel);
                                                    wcscpy_s(buscar2->DdI, ddi);
                                                    wcscpy_s(buscar2->sexo, sex);
                                                    wcscpy_s(buscar2->GO, go);
                                                    wcscpy_s(buscar2->PR, pr);




                                                    //agregar_paciente(lista2, pater, mater, nombs, nomc, curp, rfc, nacim, call, col, cid, edo, edociv, tel, ddi, sex, go, pr, numpac);
                                                    MessageBox(hwnd, L"Paciente Registrado", L"Registrar cliente", MB_ICONINFORMATION);
                                                    EndDialog(hwnd, wParam);
                                                }
                                                else {
                                                    MessageBox(hwnd, L"El grupo ocupacional y/o perfil de riesgo no puede contener ", L"Aviso", MB_ICONEXCLAMATION);
                                                }
                                            }
                                            else {

                                                MessageBox(hwnd, L"Ingrese un teléfono válido", L"Aviso", MB_ICONEXCLAMATION);
                                            }

                                        }
                                        else {
                                            MessageBox(hwnd, L"La dirrección del paciente no puede contener simbolos", L"Aviso", MB_ICONEXCLAMATION);
                                        }
                                    }
                                    else {
                                        MessageBox(hwnd, L"Ya hay un paciente con ese RFC", L"Aviso", MB_ICONEXCLAMATION);
                                    }
                                }
                                else {
                                    MessageBox(hwnd, L"El RFC no puede contener simbolos o espacios", L"Aviso", MB_ICONEXCLAMATION);
                                }
                            }
                            else {
                                MessageBox(hwnd, L"Ya hay un paciente con ese CURP", L"Aviso", MB_ICONEXCLAMATION);
                            }
                        }
                        else {
                            MessageBox(hwnd, L"El CURP no puede contener simbolos o espacios", L"Aviso", MB_ICONEXCLAMATION);
                        }
                    }
                    else {
                        MessageBox(hwnd, L"Ya hay un paciente registrado con ese nombre", L"Aviso", MB_ICONEXCLAMATION);
                    }
                }
                else {
                    MessageBox(hwnd, L"El nombre solo puede contener letras", L"Aviso", MB_ICONEXCLAMATION);
                }
            }

            break;
        case IDC_BUTTON2:

            EndDialog(hwnd, wParam);
            
            break;
        case IDC_BUTTON3:
            AbrirImagen(hwnd);

            hBitmap1 = (HBITMAP)LoadImage(NULL, img, IMAGE_BITMAP, 100, 100, LR_LOADFROMFILE);
            SendDlgItemMessage(hwnd, IDC_PICTUREC, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap1);
            break;

        }
        break;
    case WM_CLOSE:

        DestroyWindow(hwnd);
        DestroyMenu(hMenu);
        
        break;

    }

    return FALSE;
}
BOOL CALLBACK ActPac(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_CREATE:
    case WM_INITDIALOG:


        h_edit = GetDlgItem(hwnd, IDC_BUTTON1);
        SetWindowText(h_edit, L"Actualizar paciente");
        h_edit = GetDlgItem(hwnd, IDC_BUTTON2);
        SetWindowText(h_edit, L"Eliminar paciente");
        a9 = GetDlgItem(hwnd, IDC_STATIC0);
        SetWindowText(a9, buscar2->nombrecom);
        a10 = GetDlgItem(hwnd, IDC_STATIC2);
        SetWindowText(a10, buscar2->CURP);
        a11 = GetDlgItem(hwnd, IDC_STATIC3);
        SetWindowText(a11, buscar2->RFC);
        a12 = GetDlgItem(hwnd, IDC_STATIC4);

        wcscpy_s(direccion, buscar2->calle);
        wcscat_s(direccion, L", ");
        wcscat_s(direccion, buscar2->colonia);
        wcscat_s(direccion, L", ");
        wcscat_s(direccion, buscar2->ciudad);
        wcscat_s(direccion, L", ");
        wcscat_s(direccion, buscar2->estado);

        SetWindowText(a12, direccion);
        a13 = GetDlgItem(hwnd, IDC_STATIC5);
        SetWindowText(a13, buscar2->telefono);
        a14 = GetDlgItem(hwnd, IDC_STATIC6);
        SetWindowText(a14, buscar2->nacimiento);
        a25 = GetDlgItem(hwnd, IDC_STATIC7);
        SetWindowText(a25, buscar2->sexo);
        a26 = GetDlgItem(hwnd, IDC_STATIC8);
        SetWindowText(a26, buscar2->edocivil);  
        a32 = GetDlgItem(hwnd, IDC_STATIC9);
        SetWindowText(a32, buscar2->GO);
        a33 = GetDlgItem(hwnd, IDC_STATIC10);
        SetWindowText(a33, buscar2->PR);

        h_listbox4 = GetDlgItem(hwnd, IDC_LIST1);
        listado_carpaciente(lista4);
        hBitmap2 = (HBITMAP)LoadImage(NULL, buscar2->DdI, IMAGE_BITMAP, 100, 100, LR_LOADFROMFILE);
        SendDlgItemMessage(hwnd, IDC_PICTUREC, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap2);


        //listado_conspac(lista4);

        break;
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case ID_ARCHIVO_GUARDAR:
            MessageBox(hwnd, L"mensaje", L"titulo", MB_ICONEXCLAMATION);
            break;
        case ID_ARCHIVO_GUARDARCOMO:
            MessageBox(hwnd, L"mensaje", L"titulo", MB_ICONEXCLAMATION);
            break;
        case IDC_BUTTON1:
            DialogBox(NULL, MAKEINTRESOURCE(IDD_NEWPAC), hwnd, (DLGPROC)NuevPaciente);
           

            SetWindowText(a9, buscar2->nombrecom);

            SetWindowText(a10, buscar2->CURP);
           
            SetWindowText(a11, buscar2->RFC);
            

            wcscpy_s(direccion, buscar2->calle);
            wcscat_s(direccion, L", ");
            wcscat_s(direccion, buscar2->colonia);
            wcscat_s(direccion, L", ");
            wcscat_s(direccion, buscar2->ciudad);
            wcscat_s(direccion, L", ");
            wcscat_s(direccion, buscar2->estado);

            SetWindowText(a12, direccion);
           
            SetWindowText(a13, buscar2->telefono);
           
            SetWindowText(a14, buscar2->nacimiento);
      
            SetWindowText(a25, buscar2->sexo);
          
            SetWindowText(a26, buscar2->edocivil);
           
            SetWindowText(a32, buscar2->GO);
        
            SetWindowText(a33, buscar2->PR);

            hBitmap2 = (HBITMAP)LoadImage(NULL, buscar2->DdI, IMAGE_BITMAP, 100, 100, LR_LOADFROMFILE);
            SendDlgItemMessage(hwnd, IDC_PICTUREC, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap2);

            break;
        case IDC_BUTTON2:
            
                DialogBox(NULL, MAKEINTRESOURCE(IDD_CONFIRMAR), hwnd, (DLGPROC)Confirmar);
                if (confirmar == true) {
                    wcscpy_s(Buscar_Paciente, buscar2->CURP);
                    borrar_paciente(lista2, Buscar_Paciente);
                    MessageBox(hwnd, L"Paciente Eliminado", L"Eliminar paciente", MB_ICONEXCLAMATION);
                    EndDialog(hwnd, wParam);
                }
            

            break;
        case IDC_BUTTON3:
            wcscpy_s(Carne_Paciente, L"NULL");
            index = SendDlgItemMessage(hwnd, IDC_LIST1, LB_GETCURSEL, 0, 0);
            SendDlgItemMessage(hwnd, IDC_LIST1, LB_GETTEXT, index, (LPARAM)Carne_Paciente);

            if (wcscmp(Carne_Paciente, L"NULL") == 0) {
                MessageBox(hwnd, L"No se seleccionó una opción", L"Aviso", MB_ICONEXCLAMATION);

            }
            else {
                buscar4 = lista4;
                while ((buscar4 != nullptr) && ((wcscmp(Carne_Paciente, buscar4->ID) != 0))) {

                    buscar4 = buscar4->siguiente;
                }
                wcscpy_s(Buscar_Carne, Carne_Paciente);
                DialogBox(NULL, MAKEINTRESOURCE(IDD_CARNE), hwnd, (DLGPROC)Carne);
            }


            break;
        case IDC_BUTTON5:
            EndDialog(hwnd, wParam);


            break;
        }
        break;
    case WM_CLOSE:
       // DeleteObject((HBITMAP)hBitmap);
        DestroyWindow(hwnd);
        DestroyMenu(hMenu);
      
        break;
    }
    return FALSE;
}

//Vacunas---------------------------------------------------------------------------------------------------------------------
void agregar_vacuna(vacunas*& lista3, wchar_t tip[50], wchar_t marc[50], wchar_t clavac[50], wchar_t desc[100], float price, int dos) {

    vacunas* siguiente;
    vacunas* nueva_vacuna = new vacunas();
    vacunas* aux;

    /*wcscpy_s(nueva_vacuna->nomvacuna, nomvac);*/
    wcscpy_s(nueva_vacuna->tipo, tip);
    wcscpy_s(nueva_vacuna->marca, marc);
    wcscpy_s(nueva_vacuna->clavacuna, clavac);
    wcscpy_s(nueva_vacuna->descripcion, desc);
    nueva_vacuna->precio = price;
    nueva_vacuna->dosis = dos;
    
    nueva_vacuna->siguiente = nullptr;
    nueva_vacuna->anterior = nullptr;

    if (lista3 == nullptr) {  //si la lista esta vacia
        lista3 = nueva_vacuna;  //agregamos el primer elemento a la lista
    }
    else {
        aux = lista3;  //aux apunta al inicio de la lista

        while (aux->siguiente != nullptr) {  //recorrer la lista
            aux = aux->siguiente;  //avanzamos posiciones en la lista
        }
        aux->siguiente = nueva_vacuna;  //se agrega el nuevo nodo a la lista
        aux->siguiente->siguiente = nullptr;
        aux->siguiente->anterior = aux;
        aux = aux->siguiente;
    }
    
    n++;
}
void borrar_vacuna(vacunas*& lista3, wchar_t Buscar_Vacuna[50]) {

    vacunas* aux_borrar;
    vacunas* anterior = nullptr;
    aux_borrar = lista3;

    while ((aux_borrar != nullptr) && (wcscmp(Buscar_Vacuna, aux_borrar->clavacuna) != 0)) {
       // recorrer la lista

        anterior = aux_borrar;
        aux_borrar = aux_borrar->siguiente;
    }

    if (aux_borrar == nullptr) { //El elemento no ha sido encontrado
        cout << endl << ">Promocion no encontrada" << endl;
    }
    else if (anterior == nullptr) {  //El elemento a eliminar es el primero

        lista3 = lista3->siguiente;
        delete aux_borrar;
         cout << endl << ">Promocion eliminada" << endl;
    }
    else {  //El elemento a eliminar no es el primero
        anterior->siguiente = aux_borrar->siguiente;
        delete aux_borrar;
         cout << endl << ">Promocion eliminada" << endl;
    }

    n--;
}
BOOL CALLBACK NuevVacuna(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg)
    {
    case WM_CREATE:
    case WM_INITDIALOG:
      
        h_combobox = GetDlgItem(hwnd, IDC_COMBO1);
        SendMessage(h_combobox, CB_ADDSTRING, (WPARAM)0, (LPARAM)L"ARN mensajero");
        SendMessage(h_combobox, CB_ADDSTRING, (WPARAM)0, (LPARAM)L"Subunidades proteicas");
        SendMessage(h_combobox, CB_ADDSTRING, (WPARAM)0, (LPARAM)L"Vector viral");
        SendMessage(h_combobox, CB_ADDSTRING, (WPARAM)0, (LPARAM)L"Otro");
      


        if (nuevo == true) {
            g19 = GetDlgItem(hwnd, IDC_EDIT1);
            SetWindowText(g19, L"{PENDIENTE}");
            g20 = GetDlgItem(hwnd, IDC_EDIT2);
            SetWindowText(g20, L"{PENDIENTE}");
            g21 = GetDlgItem(hwnd, IDC_EDIT3);
            SetWindowText(g21, L"{PENDIENTE}");
            g25 = GetDlgItem(hwnd, IDC_EDIT4);
            SetWindowText(g25, L"{PENDIENTE}");
            g36 = GetDlgItem(hwnd, IDC_EDIT5);
            SetWindowText(g36, L"{PENDIENTE}");

        }
        else {
            wchar_t dummy[60];
            //SendMessage(h_combobox, CB_ADDSTRING, (WPARAM)0, (LPARAM)buscar3->tipo);
            g19 = GetDlgItem(hwnd, IDC_EDIT1);
            SetWindowText(g19, buscar3->marca);
            g20 = GetDlgItem(hwnd, IDC_EDIT2);
            SetWindowText(g20, buscar3->clavacuna);
            g21 = GetDlgItem(hwnd, IDC_EDIT3);
            _itow_s(buscar3->dosis, dummy, 60, 10);
            SetWindowText(g21, dummy);
            g25 = GetDlgItem(hwnd, IDC_EDIT4);
            _itow_s(buscar3->precio, dummy, 60, 10);
            SetWindowText(g25, dummy);
            g36 = GetDlgItem(hwnd, IDC_EDIT5);
            SetWindowText(g36, buscar3->descripcion);

        }
        SendMessage(g19, EM_SETLIMITTEXT, 50, 0);
        SendMessage(g20, EM_SETLIMITTEXT, 50, 0);
        SendMessage(g36, EM_SETLIMITTEXT, 100, 0);

        break;

    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
            /*case ID_ARCHIVO_GUARDAR:
                MessageBox(hwnd, L"mensaje", L"titulo", MB_ICONEXCLAMATION);
                break;
            case ID_ARCHIVO_GUARDARCOMO:
                MessageBox(hwnd, L"mensaje", L"ttulo", MB_ICONEXCLAMATION);
                break;*/
        case IDC_BUTTON1:
            if (nuevo == true) {
                GetWindowText(g19, (LPWSTR)marc, sizeof(marc));
                wcscpy_s(PH, marc);
                VASIM(hwnd, PH);
                if (Cvalid == true) {
                    GetWindowText(g20, (LPWSTR)clavac, sizeof(clavac));
                    wcscpy_s(PH, clavac);
                    VASIM(hwnd, PH);
                    
                    validar3 = lista3;
                    while ((validar3 != nullptr) && (wcscmp(clavac, validar3->clavacuna) != 0) ) {

                        validar3 = validar3->siguiente;

                    }
                    if ((validar3 == nullptr) && (Cvalid == true)) {
                        GetWindowText(g21, (LPWSTR)dosi, sizeof(dosi));
                        dos = _wtof(dosi);
                        if (dos > 0) {
                            GetWindowText(g25, (LPWSTR)preci, sizeof(preci));
                            price = _wtof(preci);
                            if (price > 0) {
                                wchar_t dummy[60];
                                
                                wcscpy_s(tip, L"NULL");
                                /*index = SendDlgItemMessage(hwnd, IDC_COMBO1, CB_GETCURSEL, 0, 0);
                                SendDlgItemMessage(hwnd, IDC_COMBO1, CB_GETLBTEXT, index, (LPARAM)tip);*/
                                SendMessage(h_combobox, CB_GETLBTEXT, SendMessage(h_combobox, CB_GETCURSEL, 0, 0), (LPARAM)tip);

                                if (wcscmp(tip, L"NULL") != 0) {

                                    GetWindowText(g36, (LPWSTR)desc, sizeof(desc));
                                    agregar_vacuna(lista3, tip, marc, clavac, desc, price, dos);
                                    MessageBox(hwnd, L"Vacuna Registrada", L"Registrar vacuna", MB_ICONINFORMATION);
                                    EndDialog(hwnd, wParam);
                                }
                                else {
                                    MessageBox(hwnd, L"No se seleccionó el tipo de vacuna", L"Aviso", MB_ICONEXCLAMATION);
                                }
                            }
                            else {
                                MessageBox(hwnd, L"El precio tiene que ser mayor a 0", L"Aviso", MB_ICONEXCLAMATION);
                            }
                        }
                        else {
                            MessageBox(hwnd, L"La dosis tiene que ser mayor a 0", L"Aviso", MB_ICONEXCLAMATION);
                        }

                    }
                    else {
                        MessageBox(hwnd, L"Ya hay una vacuna con esa clave", L"Aviso", MB_ICONEXCLAMATION);
                    }

                }
                else {
                    MessageBox(hwnd, L"El nombre de la marca tiene caracteres invalidos", L"Aviso", MB_ICONEXCLAMATION);
                }
            }
            else {
                if (nuevo == false) {
                    GetWindowText(g19, (LPWSTR)marc, sizeof(marc));
                    wcscpy_s(PH, marc);
                    VASIM(hwnd, PH);
                    if (Cvalid == true) {
                        GetWindowText(g20, (LPWSTR)clavac, sizeof(clavac));
                        wcscpy_s(PH, clavac);
                        VASIM(hwnd, PH);

                        validar3 = lista3;
                        while ((validar3 != nullptr) && ((wcscmp(clavac, validar3->clavacuna) != 0) || (wcscmp(clavac, buscar3->clavacuna) == 0))) {

                            validar3 = validar3->siguiente;

                        }
                        if ((validar3 == nullptr) && (Cvalid == true)) {
                            GetWindowText(g21, (LPWSTR)dosi, sizeof(dosi));
                            dos = _wtof(dosi);
                            if (dos > 0) {
                                GetWindowText(g25, (LPWSTR)preci, sizeof(preci));
                                price = _wtof(preci);
                                if (price > 0) {
                                    wchar_t dummy[60];

                                    wcscpy_s(tip, L"NULL");
                                    /*index = SendDlgItemMessage(hwnd, IDC_COMBO1, CB_GETCURSEL, 0, 0);
                                    SendDlgItemMessage(hwnd, IDC_COMBO1, CB_GETLBTEXT, index, (LPARAM)tip);*/
                                    SendMessage(h_combobox, CB_GETLBTEXT, SendMessage(h_combobox, CB_GETCURSEL, 0, 0), (LPARAM)tip);

                                    if (wcscmp(tip, L"NULL") != 0) {

                                        GetWindowText(g36, (LPWSTR)desc, sizeof(desc));

                                        wcscpy_s(buscar3->clavacuna, clavac);
                                        wcscpy_s(buscar3->marca, marc);
                                        wcscpy_s(buscar3->descripcion, desc);
                                        wcscpy_s(buscar3->tipo, tip);

                                        buscar3->precio = price;
                                        buscar3->dosis = dos;

                                        //agregar_vacuna(lista3, tip, marc, clavac, desc, price, dos);
                                        MessageBox(hwnd, L"Vacuna Actualizada", L"Actualizar vacuna", MB_ICONINFORMATION);
                                        EndDialog(hwnd, wParam);
                                    }
                                    else {
                                        MessageBox(hwnd, L"No se seleccionó el tipo de vacuna", L"Aviso", MB_ICONEXCLAMATION);
                                    }
                                }
                                else {
                                    MessageBox(hwnd, L"El precio tiene que ser mayor a 0", L"Aviso", MB_ICONEXCLAMATION);
                                }
                            }
                            else {
                                MessageBox(hwnd, L"La dosis tiene que ser mayor a 0", L"Aviso", MB_ICONEXCLAMATION);
                            }

                        }
                        else {
                            MessageBox(hwnd, L"Ya hay una vacuna con esa clave", L"Aviso", MB_ICONEXCLAMATION);
                        }

                    }
                    else {
                        MessageBox(hwnd, L"El nombre de la marca tiene caracteres invalidos", L"Aviso", MB_ICONEXCLAMATION);
                    }
                }
            }
            break;
        case IDC_BUTTON2:

            EndDialog(hwnd, wParam);
            break;

        }
        break;
    case WM_CLOSE:

        DestroyWindow(hwnd);
        DestroyMenu(hMenu);
       
        break;

    }

    return FALSE;
}
BOOL CALLBACK ActVacuna(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_CREATE:
    case WM_INITDIALOG:
        wchar_t dummy[60];

       /* h_edit = GetDlgItem(hwnd, IDC_BUTTON1);
        SetWindowText(h_edit, L"Actualizar promocion");
        h_edit = GetDlgItem(hwnd, IDC_BUTTON2);
        SetWindowText(h_edit, L"Eliminar promocion");*/
        a15 = GetDlgItem(hwnd, IDC_STATIC0);
        SetWindowText(a15, buscar3->clavacuna);
        a16 = GetDlgItem(hwnd, IDC_STATIC2);
        
        SetWindowText(a16, buscar3->tipo);
        a17 = GetDlgItem(hwnd, IDC_STATIC3);        
        SetWindowText(a17, buscar3->marca);

        a18 = GetDlgItem(hwnd, IDC_STATIC4);
        _itow_s(buscar3->dosis, dummy, 60, 10);
        wcscat_s(dummy, L" unidades");
        SetWindowText(a18, dummy);
       
        a19 = GetDlgItem(hwnd, IDC_STATIC5);
        wcscpy_s(dummy, L"$");
        _itow_s(buscar3->precio, dummy, 60, 10);
        SetWindowText(a19, dummy);

        a34 = GetDlgItem(hwnd, IDC_STATIC6);
        SetWindowText(a34, buscar3->descripcion);

        break;
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case ID_ARCHIVO_GUARDAR:
            MessageBox(hwnd, L"mensaje", L"titulo", MB_ICONEXCLAMATION);
            break;
        case ID_ARCHIVO_GUARDARCOMO:
            MessageBox(hwnd, L"mensaje", L"titulo", MB_ICONEXCLAMATION);
            break;
        case IDC_BUTTON1:
           
                DialogBox(NULL, MAKEINTRESOURCE(IDD_NEWVAC), hwnd, (DLGPROC)NuevVacuna);
                //CloseWindow(hwnd);

               
                SetWindowText(a15, buscar3->clavacuna);
                

                SetWindowText(a16, buscar3->tipo);
               
                SetWindowText(a17, buscar3->marca);

               
                _itow_s(buscar3->dosis, dummy, 60, 10);
                wcscat_s(dummy, L" unidades");
                SetWindowText(a18, dummy);

                
                wcscpy_s(dummy, L"$");
                _itow_s(buscar3->precio, dummy, 60, 10);
                SetWindowText(a19, dummy);

               
                SetWindowText(a34, buscar3->descripcion);

            
            break;
        case IDC_BUTTON2:
          
                DialogBox(NULL, MAKEINTRESOURCE(IDD_CONFIRMAR), hwnd, (DLGPROC)Confirmar);
                if (confirmar == true) {
                    borrar_vacuna(lista3, Buscar_Vacuna);
                    MessageBox(hwnd, L"Vacuna Eliminada", L"Eliminar vacuna", MB_ICONINFORMATION);
                    EndDialog(hwnd, wParam);
                }
            
           

            break;
        case IDC_BUTTON5:
            EndDialog(hwnd, wParam);


            break;
        }
        break;
    case WM_CLOSE:
       
        DestroyWindow(hwnd);
        DestroyMenu(hMenu);
       
        break;
    }
    return FALSE;
}

//Carne------------------------------------------------------------------------------------------------------------------------
void agregar_carne(carnes*& lista4, wchar_t id[50], wchar_t carpa[50], wchar_t carvac[50], wchar_t date[50], wchar_t lot[50],wchar_t cent[50], float tot, int cardos) {

    carnes* nuevo_carne = new carnes();
    carnes* aux;
    wcscpy_s(nuevo_carne->ID, id);
    wcscpy_s(nuevo_carne->carpaciente, carpa);
    wcscpy_s(nuevo_carne->carvacuna, carvac);
    wcscpy_s(nuevo_carne->fecha, date);
    wcscpy_s(nuevo_carne->lote, lot);
    wcscpy_s(nuevo_carne->centro, cent);
    nuevo_carne->total = tot;
    nuevo_carne->cardosis = cardos;
  
    nuevo_carne->siguiente = nullptr;
    nuevo_carne->anterior = nullptr;

    if (lista4 == nullptr) {  //si la lista esta vacia
        lista4 = nuevo_carne;  //agregamos el primer elemento a la lista
    }
    else {
        aux = lista4;  //aux apunta al inicio de la lista

        while (aux->siguiente != nullptr) {  //recorrer la lista
            aux = aux->siguiente;  //avanzamos posiciones en la lista
        }
        aux->siguiente = nuevo_carne;  //se agrega el nuevo nodo a la lista
        aux->siguiente->siguiente = nullptr;
        aux->siguiente->anterior = aux;
        aux = aux->siguiente;
    }
    //cout << "\n>Promocion registrada" << endl;
    o++;
}
void borrar_carne(carnes*& lista4, wchar_t Buscar_Carne[50]) {

    carnes* aux_borrar;
    carnes* anterior = nullptr;
    aux_borrar = lista4;

    while ((aux_borrar != nullptr) && (wcscmp(Buscar_Carne, aux_borrar->ID) != 0)) {
        //recorrer la lista

        anterior = aux_borrar;
        aux_borrar = aux_borrar->siguiente;
    }

    if (aux_borrar == nullptr) { //El elemento no ha sido encontrado
        //cout << endl << ">Promocion no encontrada" << endl;
    }
    else if (anterior == nullptr) {  //El elemento a eliminar es el primero

        lista4 = lista4->siguiente;
        delete aux_borrar;
        // cout << endl << ">Promocion eliminada" << endl;
    }
    else {  //El elemento a eliminar no es el primero
        anterior->siguiente = aux_borrar->siguiente;
        delete aux_borrar;
        // cout << endl << ">Promocion eliminada" << endl;
    }

    o--;
}
BOOL CALLBACK NuevCarne(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg)
    {
    case WM_CREATE:
    case WM_INITDIALOG:
        if (nuevo == true) {
            g22 = GetDlgItem(hwnd, IDC_EDIT1);
            SetWindowText(g22, L"{PENDIENTE}");
            g37 = GetDlgItem(hwnd, IDC_EDIT2);
            SetWindowTextW(g37, L"{PENDIENTE}");
            g38 = GetDlgItem(hwnd, IDC_EDIT3);
            SetWindowTextW(g38, L"{PENDIENTE}");
        }
        else {
            g22 = GetDlgItem(hwnd, IDC_EDIT1);
            wchar_t dummy[5];
            _itow_s(buscar4->cardosis, dummy, 5, 10);
            SetWindowText(g22, dummy);
            g37 = GetDlgItem(hwnd, IDC_EDIT2);
            SetWindowTextW(g37, buscar4->centro);
            g38 = GetDlgItem(hwnd, IDC_EDIT3);
            SetWindowTextW(g38, buscar4->lote);
        }
       
        g26 = GetDlgItem(hwnd, IDC_DATETIMEPICKER1);

        a35 = GetDlgItem(hwnd, IDC_STATIC0);
        a36 = GetDlgItem(hwnd, IDC_STATIC1);
        a37 = GetDlgItem(hwnd, IDC_STATIC2);
        a38 = GetDlgItem(hwnd, IDC_STATIC3);
        a39 = GetDlgItem(hwnd, IDC_STATIC4);
        a40 = GetDlgItem(hwnd, IDC_STATIC5);
        a41 = GetDlgItem(hwnd, IDC_STATIC6);

        h_listbox2 = GetDlgItem(hwnd, IDC_LIST1);
        listado_pacientes(lista2);
        h_listbox3 = GetDlgItem(hwnd, IDC_LIST2);
        listado_vacunas(lista3);


    case WM_COMMAND:
        switch (LOWORD(wParam))
        {

        case IDC_BUTTON1:
            if (nuevo == true) {
                buscar2 = lista2;

                wcscpy_s(Paciente_Carne, L"NULL");
                index = SendDlgItemMessage(hwnd, IDC_LIST1, LB_GETCURSEL, 0, 0);
                SendDlgItemMessage(hwnd, IDC_LIST1, LB_GETTEXT, index, (LPARAM)Paciente_Carne);

                if (wcscmp(Paciente_Carne, L"No hay pacientes registrados") == 0) {
                    MessageBox(hwnd, L"No hay pacientes registrados", L"Aviso", MB_ICONEXCLAMATION);
                    regresar = true;
                }
                else if (wcscmp(Paciente_Carne, L"NULL") == 0) {
                    MessageBox(hwnd, L"No se seleccionó una opción", L"Aviso", MB_ICONEXCLAMATION);
                    regresar = true;
                }
                else {
                    while ((buscar2 != nullptr) && (wcscmp(Paciente_Carne, buscar2->CURP) != 0)) {

                        buscar2 = buscar2->siguiente;
                    }

                    //regresar = false;
                    wchar_t j[2];
                    wcscpy_s(id, L"C#");
                    _itow_s(o + 1, j, 2, 10);
                    wcscat_s(id, j);
                    wcscat_s(id, L" ");
                    wcscat_s(id, Paciente_Carne);



                    wcscpy_s(Vacuna_Carne, L"NULL");
                    index = SendDlgItemMessage(hwnd, IDC_LIST2, LB_GETCURSEL, 0, 0);
                    SendDlgItemMessage(hwnd, IDC_LIST2, LB_GETTEXT, index, (LPARAM)Vacuna_Carne);

                    if (wcscmp(Vacuna_Carne, L"No hay vacunas registradas") == 0) {
                        MessageBox(hwnd, L"No hay vacunas registradas", L"Aviso", MB_ICONEXCLAMATION);
                        regresar = true;
                    }
                    else if (wcscmp(Vacuna_Carne, L"NULL") == 0) {
                        MessageBox(hwnd, L"No se seleccionó una opción", L"Aviso", MB_ICONEXCLAMATION);
                        regresar = true;
                    }
                    else {
                        buscar3 = lista3;
                        while ((buscar3 != nullptr) && (wcscmp(Vacuna_Carne, buscar3->clavacuna) != 0)) {

                            buscar3 = buscar3->siguiente;
                        }

                        wchar_t cardosw[10];
                        GetWindowText(g22, (LPWSTR)cardosw, sizeof(cardosw));

                        cardos = _wtof(cardosw);
                        tot = buscar3->precio * cardos;

                        if (cardos != 0) {
                            GetWindowText(g26, (LPWSTR)date, sizeof(date));
                            GetWindowText(g37, (LPWSTR)cent, sizeof(cent));
                            GetWindowText(g38, (LPWSTR)lot, sizeof(lot));
                            wcscpy_s(carpa, Paciente_Carne);
                            wcscpy_s(carvac, Vacuna_Carne);
                            wcscpy_s(Buscar_Carne, id);
                            agregar_carne(lista4, id, carpa, carvac, date, lot, cent, tot, cardos);
                            MessageBox(hwnd, L"Carné Registrado", L"Registrar carné", MB_ICONINFORMATION);
                            //DialogBox(NULL, MAKEINTRESOURCE(IDD_CARNE), hwnd, (DLGPROC)Carne);

                            regresar = false;
                            buscar2->numpaciente = o;
                            EndDialog(hwnd, wParam);

                        }
                        else {
                            MessageBox(hwnd, L"La dosis no puede ser 0", L"Aviso", MB_ICONEXCLAMATION);
                        }
                    }
                }
            }
            else {
                buscar2 = lista2;

                wcscpy_s(Paciente_Carne, L"NULL");
                index = SendDlgItemMessage(hwnd, IDC_LIST1, LB_GETCURSEL, 0, 0);
                SendDlgItemMessage(hwnd, IDC_LIST1, LB_GETTEXT, index, (LPARAM)Paciente_Carne);

                if (wcscmp(Paciente_Carne, L"No hay pacientes registrados") == 0) {
                    MessageBox(hwnd, L"No hay pacientes registrados", L"Aviso", MB_ICONEXCLAMATION);
                    regresar = true;
                }
                else if (wcscmp(Paciente_Carne, L"NULL") == 0) {
                    MessageBox(hwnd, L"No se seleccionó una opción", L"Aviso", MB_ICONEXCLAMATION);
                    regresar = true;
                }
                else {
                    while ((buscar2 != nullptr) && (wcscmp(Paciente_Carne, buscar2->CURP) != 0)) {

                        buscar2 = buscar2->siguiente;
                    }

                    //regresar = false;
                    wchar_t j[2];
                    wcscpy_s(id, L"C#");
                    _itow_s(o + 1, j, 2, 10);
                    wcscat_s(id, j);
                    wcscat_s(id, L" ");
                    wcscat_s(id, Paciente_Carne);

                    wcscpy_s(Vacuna_Carne, L"NULL");
                    index = SendDlgItemMessage(hwnd, IDC_LIST2, LB_GETCURSEL, 0, 0);
                    SendDlgItemMessage(hwnd, IDC_LIST2, LB_GETTEXT, index, (LPARAM)Vacuna_Carne);

                    if (wcscmp(Vacuna_Carne, L"No hay vacunas registradas") == 0) {
                        MessageBox(hwnd, L"No hay vacunas registradas", L"Aviso", MB_ICONEXCLAMATION);
                        regresar = true;
                    }
                    else if (wcscmp(Vacuna_Carne, L"NULL") == 0) {
                        MessageBox(hwnd, L"No se seleccionó una opción", L"Aviso", MB_ICONEXCLAMATION);
                        regresar = true;
                    }
                    else {
                        buscar3 = lista3;
                        while ((buscar3 != nullptr) && (wcscmp(Vacuna_Carne, buscar3->clavacuna) != 0)) {

                            buscar3 = buscar3->siguiente;
                        }

                        wchar_t cardosw[10];
                        GetWindowText(g22, (LPWSTR)cardosw, sizeof(cardosw));

                        cardos = _wtof(cardosw);
                        tot = buscar3->precio * cardos;

                        if (cardos != 0) {
                            GetWindowText(g26, (LPWSTR)date, sizeof(date));
                            GetWindowText(g37, (LPWSTR)cent, sizeof(cent));
                            GetWindowText(g38, (LPWSTR)lot, sizeof(lot));
                            wcscpy_s(buscar4->ID, id);
                            wcscpy_s(buscar4->carpaciente, Paciente_Carne);
                            wcscpy_s(buscar4->carvacuna, Vacuna_Carne);
                            wcscpy_s(buscar4->fecha, date);
                            wcscpy_s(buscar4->centro, cent);
                            wcscpy_s(buscar4->lote, lot);
                            buscar4->total, tot;
                            buscar4->cardosis = cardos;
                            
                            MessageBox(hwnd, L"Carné Actualizado", L"Actualizar carné", MB_ICONINFORMATION);
                            //DialogBox(NULL, MAKEINTRESOURCE(IDD_CARNE), hwnd, (DLGPROC)Carne);

                            regresar = false;

                            EndDialog(hwnd, wParam);

                        }
                        else {
                            MessageBox(hwnd, L"La dosis no puede ser 0", L"Aviso", MB_ICONEXCLAMATION);
                        }
                    }
                }
            }
            break;
        case IDC_BUTTON2:
            regresar = true;
            EndDialog(hwnd, wParam);
            break;
        case IDC_BUTTON3:
            buscar2 = lista2;
            wcscpy_s(Paciente_Carne, L"NULL");
            index = SendDlgItemMessage(hwnd, IDC_LIST1, LB_GETCURSEL, 0, 0);
            SendDlgItemMessage(hwnd, IDC_LIST1, LB_GETTEXT, index, (LPARAM)Paciente_Carne);

            if (wcscmp(Paciente_Carne, L"No hay pacientes registrados") == 0) {
                MessageBox(hwnd, L"No hay pacientes registrados", L"Aviso", MB_ICONEXCLAMATION);
                regresar = true;
            }
            else if (wcscmp(Paciente_Carne, L"NULL") == 0) {
                MessageBox(hwnd, L"No se seleccionó una opción", L"Aviso", MB_ICONEXCLAMATION);
                regresar = true;
            }
            else {
                while ((buscar2 != nullptr) && (wcscmp(Paciente_Carne, buscar2->CURP) != 0)) {

                    buscar2 = buscar2->siguiente;
                }
                SetWindowText(a35, buscar2->CURP);
                SetWindowText(a36, buscar2->nombrecom);
            }
            buscar3 = lista3;
            wcscpy_s(Vacuna_Carne, L"NULL");
            index = SendDlgItemMessage(hwnd, IDC_LIST2, LB_GETCURSEL, 0, 0);
            SendDlgItemMessage(hwnd, IDC_LIST2, LB_GETTEXT, index, (LPARAM)Vacuna_Carne);

            if (wcscmp(Vacuna_Carne, L"No hay vacunas registradas") == 0) {
                MessageBox(hwnd, L"No hay vacunas registradas", L"Aviso", MB_ICONEXCLAMATION);
                regresar = true;
            }
            else if (wcscmp(Vacuna_Carne, L"NULL") == 0) {
                MessageBox(hwnd, L"No se seleccionó una opción", L"Aviso", MB_ICONEXCLAMATION);
                regresar = true;
            }
            else {
                buscar3 = lista3;
                while ((buscar3 != nullptr) && (wcscmp(Vacuna_Carne, buscar3->clavacuna) != 0)) {

                    buscar3 = buscar3->siguiente;
                }
                SetWindowText(a37, buscar3->clavacuna);
                SetWindowText(a38, buscar3->tipo);
                SetWindowText(a39, buscar3->marca);
                //wchar_t dummy[5];
                _itow_s(buscar3->dosis, dosi, 50, 10);
                SetWindowText(a40, dosi);
                _itow_s(buscar3->precio, preci, 50, 10);
                SetWindowText(a41, preci);
                
            }
            break;
        }
        break;
    case WM_CLOSE:

        DestroyWindow(hwnd);
        DestroyMenu(hMenu);
        //DestroyWindow(ghDlg);
        break;

    }

    return FALSE;
}
BOOL CALLBACK ActCar(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_CREATE:
    case WM_INITDIALOG:
        buscar4 = lista4;
        while ((buscar4 != nullptr) && (wcscmp(Buscar_Carne, buscar4->ID) != 0)) {

            buscar4 = buscar4->siguiente;
        }
        a42 = GetDlgItem(hwnd, IDC_STATIC0);
        SetWindowText(a42, buscar4->ID);
        a43 = GetDlgItem(hwnd, IDC_STATIC2);
        SetWindowText(a43, buscar4->carpaciente);
        a44 = GetDlgItem(hwnd, IDC_STATIC3);
        SetWindowText(a44, buscar4->carvacuna);
        a45 = GetDlgItem(hwnd, IDC_STATIC4);
        wchar_t dummy[5];
        _itow_s(buscar4->cardosis, dummy, 5, 10);
        SetWindowText(a45, dummy);
        a46 = GetDlgItem(hwnd, IDC_STATIC5);
        SetWindowText(a46, buscar4->centro);
        a47 = GetDlgItem(hwnd, IDC_STATIC6);
        SetWindowText(a47, buscar4->lote);
        a48 = GetDlgItem(hwnd, IDC_STATIC7);
        SetWindowText(a48, buscar4->fecha);

        break;
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case ID_ARCHIVO_GUARDAR:
            MessageBox(hwnd, L"mensaje", L"titulo", MB_ICONEXCLAMATION);
            break;
        case ID_ARCHIVO_GUARDARCOMO:
            MessageBox(hwnd, L"mensaje", L"titulo", MB_ICONEXCLAMATION);
            break;
        case IDC_BUTTON1:
            nuevo == false;
            SetWindowText(a42, buscar4->ID);
            SetWindowText(a43, buscar4->carpaciente);
            SetWindowText(a44, buscar4->carvacuna);
            wchar_t dummy[5];
            _itow_s(buscar4->cardosis, dummy, 5, 10);
            SetWindowText(a45, dummy);
            SetWindowText(a46, buscar4->centro);
            SetWindowText(a47, buscar4->lote);
            SetWindowText(a48, buscar4->fecha);

            DialogBox(NULL, MAKEINTRESOURCE(IDD_NEWCAR), hwnd, (DLGPROC)NuevCarne);
            break;
        case IDC_BUTTON2:
            DialogBox(NULL, MAKEINTRESOURCE(IDD_CONFIRMAR), hwnd, (DLGPROC)Confirmar);
            if (confirmar == true) {
                borrar_carne(lista4, Buscar_Carne);
                MessageBox(hwnd, L"Carne Eliminado", L"Eliminar carne", MB_ICONEXCLAMATION);
                EndDialog(hwnd, wParam);
            }

            break;
        case IDC_BUTTON3:
            
            DialogBox(NULL, MAKEINTRESOURCE(IDD_CARNE), hwnd, (DLGPROC)Carne);
            break;
        case IDC_BUTTON5:
            EndDialog(hwnd, wParam);
            break;
        }
        break;
    case WM_CLOSE:
      
        DestroyWindow(hwnd);
        DestroyMenu(hMenu);
        
        break;
    }
    return FALSE;
}
BOOL CALLBACK Carne(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_CREATE:
    case WM_INITDIALOG:
        buscar4 = lista4;
        while ((buscar4 != nullptr) && (wcscmp(Buscar_Carne, buscar4->ID) != 0)) {

            buscar4 = buscar4->siguiente;
        }
        buscar3 = lista3;
        while ((buscar3 != nullptr) && (wcscmp(buscar4->carvacuna, buscar3->clavacuna) != 0)) {

            buscar3 = buscar3->siguiente;
        }
        buscar2 = lista2;
        while ((buscar2 != nullptr) && (wcscmp(buscar4->carpaciente, buscar2->CURP) != 0)) {

            buscar2 = buscar2->siguiente;
        }

        h_edit = GetDlgItem(hwnd, IDC_STATIC0);
        SetWindowText(h_edit, buscar4->ID);
        h_edit = GetDlgItem(hwnd, IDC_STATIC1);
        SetWindowText(h_edit, buscar2->nombrecom);
        h_edit = GetDlgItem(hwnd, IDC_STATIC2);
        SetWindowText(h_edit, buscar2->CURP);
        h_edit = GetDlgItem(hwnd, IDC_STATIC3);
        SetWindowText(h_edit, buscar2->RFC);
        h_edit = GetDlgItem(hwnd, IDC_STATIC4);
        SetWindowText(h_edit, buscar2->nacimiento);
        h_edit = GetDlgItem(hwnd, IDC_STATIC5);
        SetWindowText(h_edit, buscar2->sexo);
        h_edit = GetDlgItem(hwnd, IDC_STATIC6);
        SetWindowText(h_edit, buscar2->edocivil);
        h_edit = GetDlgItem(hwnd, IDC_STATIC7);
        wcscpy_s(direccion, buscar2->calle);
        wcscat_s(direccion, L", ");
        wcscat_s(direccion, buscar2->colonia);
        wcscat_s(direccion, L", ");
        wcscat_s(direccion, buscar2->ciudad);
        wcscat_s(direccion, L", ");
        wcscat_s(direccion, buscar2->estado);
        SetWindowText(h_edit, direccion);
        h_edit = GetDlgItem(hwnd, IDC_STATIC8);
        SetWindowText(h_edit, buscar2->telefono);
        h_edit = GetDlgItem(hwnd, IDC_STATIC9);
        SetWindowText(h_edit, buscar2->GO);
        h_edit = GetDlgItem(hwnd, IDC_STATIC10);
        SetWindowText(h_edit, buscar2->PR);

        h_edit = GetDlgItem(hwnd, IDC_STATIC11);
        SetWindowText(h_edit, buscar3->clavacuna);
        h_edit = GetDlgItem(hwnd, IDC_STATIC12);
        SetWindowText(h_edit, buscar3->tipo);
        h_edit = GetDlgItem(hwnd, IDC_STATIC13);
        SetWindowText(h_edit, buscar3->marca);
        h_edit = GetDlgItem(hwnd, IDC_STATIC14);
        SetWindowText(h_edit, buscar3->descripcion);
        h_edit = GetDlgItem(hwnd, IDC_STATIC15);
        wchar_t dummy[5];
        _itow_s(buscar4->cardosis, dummy, 5, 10);
        SetWindowText(h_edit, dummy);
        h_edit = GetDlgItem(hwnd, IDC_STATIC16);
        swprintf_s(preci, L"%.1f", buscar3->precio);
        SetWindowText(h_edit, preci);
        h_edit = GetDlgItem(hwnd, IDC_STATIC17);
        swprintf_s(total, L"%.1f", buscar4->total);
        SetWindowText(h_edit, total);

        h_edit = GetDlgItem(hwnd, IDC_STATIC18);
        SetWindowText(h_edit, buscar4->centro);
        h_edit = GetDlgItem(hwnd, IDC_STATIC19);
        SetWindowText(h_edit, buscar4->lote);
        h_edit = GetDlgItem(hwnd, IDC_STATIC20);
        SetWindowText(h_edit, buscar4->fecha);

        hPictureControl = GetDlgItem(hwnd, IDC_PICTUREC);
        hBitmap2 = (HBITMAP)LoadImage(NULL, buscar2->DdI, IMAGE_BITMAP, 100, 100, LR_LOADFROMFILE);
        SendDlgItemMessage(hwnd, IDC_PICTUREC, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap2);

        break;
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {

        case IDC_BUTTON1:

            EndDialog(hwnd, wParam);

            //CloseWindow(hwnd);

            break;
        case IDC_BUTTON2:
            wofstream myfile("CarneT.txt");

            myfile << buscar4->ID << "------------------" << endl;
            myfile << "  " << "Nombre: " << buscar2->nombrecom << endl;
            myfile << "  " << "CURP: " << buscar2->CURP << "               " << "RFC: " << buscar2->RFC << endl;
            myfile << "  " << "Fecha de nacimiento: " << buscar2->nacimiento << endl;
            myfile << "  " << "Sexo: " << buscar2->sexo << "               " << "Estado civil: " << buscar2->edocivil << endl;
            wcscpy_s(direccion, buscar2->calle);
            wcscat_s(direccion, L", ");
            wcscat_s(direccion, buscar2->colonia);
            wcscat_s(direccion, L", ");
            wcscat_s(direccion, buscar2->ciudad);
            wcscat_s(direccion, L", ");
            wcscat_s(direccion, buscar2->estado);
            myfile << "  " << "Dirección: " << direccion << endl;
            myfile << "  " << "Teléfono: " << buscar2->telefono << endl;
            myfile << "  " << "Grupo Ocupacional: " << buscar2->GO << endl;
            myfile << "  " << "Perfil de Riesgo: " << buscar2->PR << endl;
            myfile << "---" << buscar3->clavacuna << "---------------------------" << endl;
            myfile << "    " << "Tipo de vacuna: " << buscar3->tipo << endl;
            myfile << "    " << "Marca de vacuna: " << buscar3->marca << endl;
            myfile << "    " << "Descripción: " << endl;
            myfile << "    " << buscar3->descripcion << endl;
           /* wchar_t dummy[5];
            _itow_s(buscar4->cardosis, dummy, 5, 10);
            myfile << " " << "Número de dosis: " << dummy << endl;*/
            myfile << "----------------------------------------" << endl;
            myfile << "  " << "Número de dosis: " << buscar4->cardosis << endl;
            swprintf_s(preci, L"%.1f", buscar3->precio); swprintf_s(total, L"%.1f", buscar4->total);
            myfile << "  " << "Precio de compra: $" << preci << "               " << "Total: $" << total << endl;           
            myfile << "  " << "Centro de vacunación: " << buscar4->centro << endl;
            myfile << "  " << "Número de lote: " << buscar4->lote << endl;
            myfile << "  " << "Fecha de vacunación: " << buscar4->fecha << endl;

            MessageBox(hwnd, L"Se ha guardado un TXT con la información", L"Generar Carné", MB_ICONINFORMATION);

            EndDialog(hwnd, wParam);
            break;
        }
        break;
    case WM_CLOSE:

        EndDialog(hwnd, wParam);
        //DestroyWindow(ghDlg);
        break;
    }
    return FALSE;
}

BOOL CALLBACK Confirmar(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_CREATE:
    case WM_INITDIALOG:

        h_edit = GetDlgItem(hwnd, IDC_STATIC1);
        SetWindowText(h_edit, L"Está seguro que quiere realizar esta acción?");

        break;
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {

        case IDC_BUTTON1:
            confirmar = true;
            EndDialog(hwnd, wParam);


            break;
        case IDC_BUTTON2:
            confirmar = false;
            EndDialog(hwnd, wParam);


            break;
        }
        break;
    case WM_CLOSE:

        EndDialog(hwnd, wParam);
     
        break;
    }
    return FALSE;
}

