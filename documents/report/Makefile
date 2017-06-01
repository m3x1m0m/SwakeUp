DOC=report
PARAMS=--shell-escape

pdf: all

all:
	pdflatex $(PARAMS) $(DOC).tex
	bibtex $(DOC)
	pdflatex $(PARAMS) $(DOC).tex
	pdflatex $(PARAMS) $(DOC).tex

clean:
	rm -f $(DOC).blg $(DOC).bbl $(DOC).aux $(DOC).log $(DOC).pdf
