(require 'package)

(add-to-list 'package-archives
             '("melpa" . "https://melpa.org/packages/") t)
;(add-to-list 'package-archives
;             '("melpa-stable" . "https://stable.melpa.org/packages/") t)

(package-initialize)

(add-to-list 'load-path "~/.emacs.d/myconfig/")

(require 'setup-pkgs)
(require 'setup-general)
(require 'setup-latex)
(require 'setup-theme)


(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(company-quickhelp-delay 0.8)
 '(conda-anaconda-home "~/.anaconda3")
 '(package-selected-packages
   (quote
	(org-bullets plantuml-mode org-mind-map bibtex-utils company-reftex company-bibtex auctex-latexmk autopair dashboard-hackernews dashboard company-fuzzy company-flx anaconda-mode conda all-the-icons-dired irony company-irony-c-headers company-irony)))
 '(reftex-bibpath-environment-variables (quote ("./" "./bib"))))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(minimap-active-region-background ((((background dark)) (:background "#555555555555")) (t (:background "#C847D8FEFFFF"))) nil (quote minimap)))
