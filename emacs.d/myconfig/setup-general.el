;;; package -- summary
;;; Commentary:
;; The general setup for Emacs

;;; code:
;; Set the font and size
(setq default-frame-alist '((font . "Source Code Pro-11")))

;; Set initial window size
(when window-system (set-frame-size (selected-frame) 140 48))
(add-to-list 'default-frame-alist '(height . 48))
(add-to-list 'default-frame-alist '(width . 140))

;; basic config
(setq ring-bell-function 'ignore)
(setq inhibit-splash-screen t)
;; Ui mode config
(menu-bar-mode -1)
(scroll-bar-mode -1)
(tool-bar-mode -1)
(setq select-enable-clipboard t)
(setq-default tab-width 4)

;; display relative numbers
(add-hook 'prog-mode-hook #'display-line-numbers-mode)
(add-hook 'prog-mode-hook (lambda () (setq-local display-line-numbers 'relative)))
(global-hl-line-mode +1)

(show-paren-mode 1)


;; replace yes or not with y or n
(defalias 'yes-or-no-p #'y-or-n-p)

(save-place-mode 1)

(provide 'setup-general)
;;; setup-general.el ends here
