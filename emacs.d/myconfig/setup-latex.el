;;; package -- summary

;;; Commentary:
;; Some config to use Emacs for latex writing


;;; code:
(use-package auctex
  :defer t
  :ensure t
  :config )
  (setq TeX-PDF-mode t)
  (setq-default TeX-master nil)
  (setq TeX-auto-save t)
  (setq TeX-parse-self t)

  (setq TeX-view-program-selection
      '((output-dvi "DVI Viewer")
        (output-pdf "PDF Viewer")))

  (setq TeX-view-program-list
      '(("DVI Viewer" "evince %o")
        ("PDF Viewer" "evince %o")))
  (setq TeX-view-program-selection
	  '((output-pdf "Evince")
		(output-dvi "Evince")))

  (setq TeX-command-default "latexmk")

  (add-hook 'LaTeX-mode-hook 'TeX-source-correlate-mode)

  (setq TeX-source-correlate-start-server t)

(provide 'setup-latex)
;;; setup-latex.el ends here
