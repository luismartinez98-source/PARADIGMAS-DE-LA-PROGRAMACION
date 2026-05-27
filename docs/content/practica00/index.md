+++
date = '2026-02-20T19:37:34-08:00'
draft = false
title = 'Practica 0 manejo de repositorios'
+++
# Reporte: Herramientas para la Generación de Páginas Web Estáticas

### Nombre: Luis Angel Martinez Zamaniego

## Introducción

En este reporte se describen las herramientas fundamentales utilizadas para el desarrollo y publicación de páginas web estáticas: Markdown, Git, GitHub, Hugo y GitHub Actions. Estas herramientas permiten crear contenido, controlar versiones, colaborar y desplegar sitios web de forma eficiente.

---

## 1. Markdown

### ¿Qué es Markdown?

Markdown es un lenguaje de marcado ligero que permite dar formato a texto plano utilizando una sintaxis sencilla y fácil de leer. Fue creado por John Gruber en 2004 con el objetivo de facilitar la escritura de documentos estructurados sin necesidad de utilizar HTML.

![Markdown](./markdown.png)


### ¿Para qué se utiliza?

Markdown se utiliza principalmente para:

- Documentación técnica  
- Archivos README  
- Blogs y páginas web estáticas  
- Foros y plataformas de colaboración  
- Notas y reportes  




---

## 2. Git y GitHub

### ¿Qué es Git?

Git es un sistema de control de versiones distribuido que permite registrar cambios en archivos y coordinar el trabajo entre varias personas. Fue creado por Linus Torvalds en 2005.

![Github](./github.jpg)


Permite:

- Guardar historial de cambios  
- Volver a versiones anteriores  
- Trabajar en paralelo mediante ramas  
- Colaborar sin sobrescribir trabajo ajeno  

### ¿Qué es GitHub?

GitHub es una plataforma en la nube que permite alojar repositorios Git y facilitar la colaboración entre desarrolladores. Además, proporciona herramientas para seguimiento de cambios, control de versiones, automatización y publicación de proyectos.

### Diferencia entre Git y GitHub

- Git → herramienta de control de versiones local  
- GitHub → servicio en línea que aloja repositorios Git  

### Comandos esenciales de Git

Inicializar repositorio:


git init


Agregar archivos al área de preparación:


git add .


Guardar cambios (commit):


git commit -m "Mensaje del commit"


Ver estado del repositorio:


git status


Ver historial de commits:


git log


Agregar repositorio remoto:


git remote add origin URL_DEL_REPOSITORIO


Subir cambios a GitHub:


git push -u origin main


### Cómo crear un repositorio en GitHub

1. Iniciar sesión en GitHub  
2. Seleccionar "New repository"  
3. Asignar nombre al repositorio  
4. Elegir visibilidad (público o privado)  
5. Crear repositorio  

---

## 3. Hugo y GitHub Actions

### ¿Qué es Hugo?

Hugo es un generador de sitios web estáticos escrito en Go. Permite crear páginas web rápidas y seguras a partir de archivos de texto (generalmente Markdown).

![hugo](./hugo.jpg)


Características principales:

- Alta velocidad de generación  
- Uso de plantillas y temas  
- Sin necesidad de bases de datos  
- Ideal para blogs y portafolios  

### ¿Qué es una página web estática?

Una página estática es aquella cuyo contenido se entrega al usuario tal como está almacenado en el servidor, sin procesamiento dinámico ni bases de datos.

Ventajas:

- Mayor velocidad  
- Mayor seguridad  
- Bajo costo de hospedaje  
- Fácil despliegue  

### Cómo crear un sitio con Hugo

1. Instalar Hugo  
2. Crear un nuevo sitio:


hugo new site nombre_sitio


3. Agregar un tema  
4. Configurar el archivo `hugo.toml`  
5. Crear contenido en Markdown  
6. Ejecutar servidor local:


hugo server


---

### ¿Qué es GitHub Actions?

GitHub Actions es un servicio de automatización que permite ejecutar flujos de trabajo directamente en los repositorios de GitHub. Se utiliza para compilar proyectos, ejecutar pruebas y desplegar aplicaciones automáticamente.

### Publicación en GitHub Pages

GitHub Pages permite alojar sitios web estáticos directamente desde un repositorio.

Proceso general:

1. Subir el proyecto a GitHub  
2. Configurar GitHub Actions para construir el sitio Hugo  
3. Publicar el contenido generado  
4. Acceder al sitio mediante una URL pública  

---

## Enlaces

Repositorio del portafolio:  
https://github.com/USUARIO/NOMBRE_REPOSITORIO 

Página publicada en GitHub Pages:  
https://USUARIO.github.io/NOMBRE_REPOSITORIO  

---

## Conclusión

Las herramientas Markdown, Git, GitHub, Hugo y GitHub Actions permiten desarrollar, documentar y publicar sitios web estáticos de forma eficiente. Su integración facilita el control de versiones, la automatización del despliegue y la disponibilidad del contenido en línea, lo que resulta especialmente útil para portafolios y documentación técnica.

Repositorio: https://github.com/tuusuario/...
Sitio web: https://tuusuario.github.io/...
