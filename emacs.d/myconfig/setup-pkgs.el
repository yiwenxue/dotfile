;;; package -- summary
;;; Commentary:
;;; General set for package list


;;; code:
(use-package company
  :ensure
  :diminish
  :config
  (add-hook 'after-init-hook  'global-company-mode)
  (setq company-idle-delay 0.1)
  (setq company-echo-delay 0.1)
  (setq company-minimum-prefix-length 2)
  (setq company-selection-wrap-around t)
  (setq company-show-numbers 'left )
  (company-tng-configure-default)

  (with-eval-after-load 'company
	;(define-key company-active-map (kbd "<return>") nil)
	(define-key company-active-map (kbd "<return>") #'company-complete-selection)
	(define-key company-active-map (kbd "RET") nil)
    ;(define-key company-active-map (kbd "C-SPC") #'company-complete-selection)))
	(define-key company-active-map (kbd "C-SPC") nil)))

(use-package company-quickhelp
  :ensure t
  :diminish
  :hook
  (company-mode . company-quickhelp-mode)
  :config
  (setq company-quickhelp-delay 0.8))

(use-package irony
  :requires company
  :ensure
  :diminish
  :init
  (add-hook 'c++-mode-hook 'irony-mode)
  (add-hook 'c-mode-hook 'irony-mode)
  (add-hook 'objc-mode-hook 'irony-mode)
  (add-hook 'irony-mode-hook 'irony-cdb-autosetup-compile-options))

(use-package company-irony
  :requires company
  :diminish
  :init
  (add-to-list 'company-backends '(company-irony)))

(use-package company-irony-c-headers
  :requires company
  :ensure
  :diminish
  :init
  (add-to-list 'company-backends '(company-irony-c-headers)))

;; plugins for python
;(use-package company-jedi
;  :requires company
;  :ensure
;  :diminish
;  :init
;  (defun my/python-mode-hook ()
;	(add-to-list 'company-backends 'company-jedi))
;  (add-hook 'python-mode-hook 'my/python-mode-hook)
;  (add-hook 'python-mode-hook 'jedi:setup)
;  :config
;  (setq jedi:environment-virtualenv (list (expand-file-name "~/.emacs.d/.python-environments/")))
;    (setq jedi:complete-on-dot t)
;  )

;(use-package conda
;  :ensure
;  :diminish
;  :init
;  (conda-env-autoactivate-mode t)
;)


(use-package flycheck
  :ensure
  :init
  (global-flycheck-mode)
  (add-hook 'c++-mode-hook 'flycheck-mode)
  (add-hook 'c-mode-hook 'flycheck-mode))

(use-package flycheck-popup-tip
  :requires flycheck
  :ensure
  :diminish
  :init
  (add-hook 'flycheck-mode-hook 'flycheck-popup-tip-mode)
  )

(use-package flycheck-irony
  :requires flycheck
  :ensure
  :diminish
  :init
  (add-hook 'flycheck-mode-hook #'flycheck-irony-setup)
  :config)


(use-package yasnippet
  :requires company
  :ensure
  :diminish
  :init
  (yas-global-mode 1)
  :config
  (defvar company-mode/enable-yas t
	"Enable yasnippet for all backends.")

  (defun company-mode/backend-with-yas (backend)
	(if (or (not company-mode/enable-yas) (and (listp backend) (member 'company-yasnippet backend)))
		backend
	  (append (if (consp backend) backend (list backend))
			  '(:with company-yasnippet))))
  (setq company-backends (mapcar #'company-mode/backend-with-yas company-backends))
  )

;(use-package evil
;  :ensure
;  :init
;  (evil-mode 1))

(use-package all-the-icons
  :ensure
  :init)

(use-package minimap
  :ensure t
  :diminish
  :init
  (minimap-mode)
  :config
  (setq minimap-width-fraction 0.1)
  (setq minimap-minimum-width 20)
  (setq minimap-window-location 'right)
  :config
  (setq minimap-hide-fringes t)
  (setq minimap-update-delay 0.05)
  (custom-set-faces
   '(minimap-active-region-background
    ((((background dark)) (:background "#555555555555"))
	 (t (:background "#C847D8FEFFFF"))) :group 'minimap))
  )

(use-package centaur-tabs
  :ensure
  :diminish
  :config
  (setq centaur-tabs-style "bar")
  (setq centaur-tabs-set-icons t)
  (setq centaur-tabs-height 32)

  (setq centaur-tabs-set-bar 'under)
  (setq x-underline-at-descent-line t)

  (setq centaur-tabs-set-modified-marker t)
;  (centaur-tabs-headline-match)
  :init
  (centaur-tabs-mode t) )

(use-package magit
  :ensure
  :init
  :config
  (global-magit-file-mode)
  (global-set-key (kbd "C-x g") 'magit-status)
)

(use-package projectile
  :ensure
  :init
  (projectile-mode +1)
  (define-key projectile-mode-map (kbd "C-c p") 'projectile-command-map))

(use-package which-key
  :ensure
  :init
  (which-key-mode))

(use-package undo-tree
  :ensure
  :diminish
  :init
  (setq undo-tree-history-directory-alist '(("." . "~/.emacs.d/undo")))
  (setq undo-tree-auto-save-history t)
  (add-to-list 'display-buffer-alist
			 '("*undo-tree*" (display-buffer-reuse-window display-buffer-in-side-window)
			   (side . left) (size . 0.15)))
  (global-undo-tree-mode))

(use-package treemacs
  :ensure t
  :diminish
  :defer t
  :init
  :config
  (setq treemacs-width 30)
  (treemacs-follow-mode t)
  (treemacs-filewatch-mode t)
  (treemacs-fringe-indicator-mode t)
  (treemacs-git-mode 'deferred)
  :bind ("C-c t"   . treemacs))

(use-package treemacs-projectile
  :after treemacs projectile
  :ensure t)

(use-package treemacs-icons-dired
  :after treemacs dired
  :ensure t
  :config (treemacs-icons-dired-mode))

(use-package treemacs-magit
  :after treemacs magit
  :ensure t)

(use-package company-auctex
  :ensure
  :init
  (company-auctex-init))
(setq )
(auctex-latexmk-setup)
(setq TeX-command-default "LatexMk")
(use-package reftex
  :ensure
  :init
  (add-hook 'LaTeX-mode-hook 'turn-on-reftex)
  (setq reftex-plug-into-AUCTeX t)
  (setq reftex-bibpath-environment-variables '("./" "./bib/" "./ref" "./reference"))
  ;(setq reftex-default-bibliography '("~/Documents/research_papers/bibtex.bib"))
  (setq reftex-bibliography-commands '("bibliography" "nobibliography" "addbibresource")))

(use-package company-reftex
  :ensure
  :init
  (add-to-list 'company-backends 'company-reftex-citations)
  (add-to-list 'company-backends 'company-reftex-labels))

(use-package org-mind-map
  :init
  (require 'ox-org)
  :ensure t
  :config
  (setq org-mind-map-engine "dot"))

(use-package plantuml-mode
  :ensure
  :diminish
  :init
  (setq plantuml-default-exec-mode 'jar)
  (setq org-plantuml-jar-path (expand-file-name "~/.emacs.d/myconfig/plantuml/plantuml.jar"))
  (setq plantuml-jar-path (expand-file-name "~/.emacs.d/myconfig/plantuml/plantuml.jar"))
  (setq org-startup-with-inline-images t)
  (add-to-list 'org-src-lang-modes '("plantuml" . plantuml))
  (org-babel-do-load-languages 'org-babel-load-languages '((plantuml . t)))
  )

(use-package org-bullets
  :ensure
  :diminish
  :init
  (add-hook 'org-mode-hook (lambda () (org-bullets-mode 1))))

(use-package autopair
  :ensure
  :diminish
  :init
  (autopair-global-mode))

(provide 'setup-pkgs)
;;; setup-pkgs.el ends here
